/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:01:51 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/11 17:02:48 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("/home/hfilipe-/42/get_next_line/test/test.txt", O_RDONLY);
	fd2 = open("/home/hfilipe-/42/get_next_line/test/test2.txt", O_RDONLY);
	fd3 = open("/home/hfilipe-/42/get_next_line/test/test3.txt", O_RDONLY);
	i = 1;
	while (i <= 4)
	{
		line = get_next_line(fd1);
		printf("line txt1 [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line txt2 [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line txt3 [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}