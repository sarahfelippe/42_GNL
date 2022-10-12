/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelippe <sfelippe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:08 by sfelippe          #+#    #+#             */
/*   Updated: 2022/10/11 04:42:16 by sfelippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test2.txt", O_RDONLY);
	line = "";
	i = 1;
	while (line)
	{
		line = get_next_line(fd);
		printf("line[%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
