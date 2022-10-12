/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelippe <sfelippe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:18:52 by sfelippe          #+#    #+#             */
/*   Updated: 2022/10/12 03:37:28 by sfelippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
Function reads the file until it finds '\n' or EOF. If function finds EOF 
(return of 'read' function is equal to 0), function should return the line read
until character '\n' is found (line_before_break). If there's an error (return 
of 'read' function is equal to -1), function should return NULL. 
*/

static char	*ft_read_join_line_until_break(int fd, char *line_before_break)
{
	int		i;
	char	*read_line;

	read_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_line)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, read_line, BUFFER_SIZE);
		if (i == -1)
		{
			free (read_line);
			return (NULL);
		}
		read_line[i] = '\0';
		line_before_break = ft_strjoin(line_before_break, read_line);
		if (ft_strchr(read_line, '\n') && line_before_break)
			break ;
	}
	free (read_line);
	return (line_before_break);
}

/*
Function creates a substring of line_before_break until the character '\n' or 
EOF, and returns that substring. 
*/

static char	*ft_get_line_until_break(char *line_before_break)
{
	int		i;
	char	*return_line;

	i = 0;
	if (!line_before_break[i])
		return (NULL);
	while (line_before_break[i] != '\n' && line_before_break[i] != '\0')
		i++;
	return_line = ft_substr(line_before_break, 0, i + 1);
	return (return_line);
}

/*
Function creates a substring of line_before_break after the character '\n', and
returns that substring as the new value of line_before_break. 
*/

static char	*ft_get_line_after_break(char *line_before_break)
{
	char	*aux;

	if (ft_strchr(line_before_break, '\n'))
	{
		aux = ft_strdup(ft_strchr(line_before_break, '\n') + 1);
		free(line_before_break);
		return (aux);
	}
	else
	{
		free(line_before_break);
		return (NULL);
	}
}

/*
Function reads the file until it finds '\n' or EOF regardless of BUFFER_SIZE.
If 'fd' or BUFFER_SIZE are inexistent, function must return null. Function
must return line read including the character '\n'. 
Function is initiated by reading the file until it finds the next '\n' or EOF
and then joining all lines read until '\n' or EOF are reached (pieces of 
strings defined by BUFFER_SIZE). Later, function must return only the line read
until '\n' or EOF and, if any, store the remaining parts (string after '\n') to
be returned if function is called again.
*/

char	*get_next_line(int fd)
{
	static char	*line_before_break[FD_MAX];
	char		*return_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line_before_break[fd] = ft_read_join_line_until_break(fd, \
													line_before_break[fd]);
	if (!line_before_break[fd])
		return (NULL);
	return_line = ft_get_line_until_break(line_before_break[fd]);
	line_before_break[fd] = ft_get_line_after_break(line_before_break[fd]);
	return (return_line);
}
