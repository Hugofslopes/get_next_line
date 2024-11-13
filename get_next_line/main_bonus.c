/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:01:51 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/13 20:12:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1, fd2, fd3, fd4, fd5;

	//test 1char
	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i <= 4)
	{
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd1);
	puts("\n");
	puts("\n");
	//test same 1 char 
	fd1 = open("test.txt", O_RDONLY);
	i = 0;
	while (i <= 4)
	{
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd1);
	puts("\n");
	puts("\n");
	//test big 
	fd3 = open("test1.txt", O_RDONLY);
	i = 0;
	while (i <= 655)
	{
		line = get_next_line(fd3);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd3);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd3);
	puts("\n");
	puts("\n");
	//test 2 fd
	fd1 = open("test.txt", O_RDONLY);
	fd3 = open("test1.txt", O_RDONLY);
	i = 0;
	while (i <= 1340)
	{
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd3);
		printf("txt2 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd3);
	close(fd1);
	puts("\n");
	puts("\n");
	//test empty
	fd2 = open("test2.txt", O_RDONLY);
	i = 0;
	while (i <= 10)
	{
		line = get_next_line(fd1);
		printf("txt3 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd1);
		printf("txt3 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	}
	close(fd2);
	puts("\n");
	puts("\n");
	//test multiple
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test1.txt", O_RDONLY);
	fd4 = open("test3.txt", O_RDONLY);
	fd5 = open("test4.txt", O_RDONLY);
	i = 0;
	while (i <= 3270)
	{
		line = get_next_line(fd1);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd2);
		printf("txt2 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd3);
		printf("txt3 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd4);
		printf("txt4 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd5);
		printf("txt5 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		
	}
	close(fd3);
	close(fd1);
	puts("\n");
	puts("\n");
}
