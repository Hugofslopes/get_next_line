/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/14 10:15:50 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int				fd;
	char			*line;
	unsigned int	i;

puts("\e[41mTEST ONE CHAR\e[0m");
	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i <= 4)
	{
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");

puts("\e[41mREOPEN FD\e[0m");
	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i <= 4)
	{
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");

puts("\e[41mTEST EMPTY FILE\e[0m");
	fd = open("test2.txt", O_RDONLY);
	i = 0;
	while (i <= 10)
	{
		line = get_next_line(fd);
		printf("txt3 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt3 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");

puts("\e[41mTEST ONE \\n\e[0m");
	fd = open("test5.txt", O_RDONLY);
	i = 0;
	while (i <= 3)
	{
		line = get_next_line(fd);
		printf("txt5 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");

puts("\e[41mTEST SEVERAL \\n\e[0m");
	fd = open("test6.txt", O_RDONLY);
	i = 0;
	while (i <= 5)
	{
		line = get_next_line(fd);
		printf("txt6 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");
	
puts("\e[41mTEST REOPEN SEVERAL \\n\e[0m");	
	fd = open("test6.txt", O_RDONLY);
	i = 0;
	while (i <= 5)
	{
		line = get_next_line(fd);
		printf("txt6 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
	puts("\n");
	puts("\n");
	
puts("\e[41mTEST BIG FILE\e[0m");
	fd = open("test1.txt", O_RDONLY);
	i = 0;
	while (i <= 655)
	{
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd);
}
