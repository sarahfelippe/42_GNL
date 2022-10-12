/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelippe <sfelippe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:08 by sfelippe          #+#    #+#             */
/*   Updated: 2022/10/12 03:10:21 by sfelippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	fd1 = open("test0.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	fd3 = open("test2.txt", O_RDONLY);
	line = "";
	i = 1;
	while (line)
	{
		line = get_next_line_bonus(fd1);
		printf("line[%d]: %s\n", i, line);
		free(line);
		line = get_next_line_bonus(fd2);
		printf("line[%d]: %s\n", i, line);
		free(line);
		line = get_next_line_bonus(fd3);
		printf("line[%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
