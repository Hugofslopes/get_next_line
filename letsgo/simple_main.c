/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:12:46 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/18 22:02:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int				fd;
	char			*line;
	unsigned int	i;

puts("\e[41mTEST ONE CHAR\e[0m");
	fd = open("42_with_nl", O_RDONLY);
	i = 1;
	/* while (i <= 4)
	{
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
		line = get_next_line(fd);
		printf("txt1 %d: \033[34m%s\033[0m", i++, line);
		free(line);
	} */
	line = get_next_line(fd);
	printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	free(line);
	line = get_next_line(fd);
	printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	free(line);
	line = get_next_line(fd);
	printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	free(line);
	puts("");
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// close(fd);
	// fd = open("41_with_nl", O_RDONLY);
	// line = get_next_line(fd);
	// 	printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// 	free(line);
	
	// line = get_next_line(fd);
	// printf("txt1 %d: \033[34m%s\033[0m", i++, line);
	// free(line);
	// puts("");
	close(fd);
}