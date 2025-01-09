/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:01:51 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/19 11:30:42 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include "colors.h"

int	main(void)
{
	char	*line;
	unsigned int	i;
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	unsigned int	j;

	i = 1;
	puts(BG_BRIGHT_WHITE BOLD BLUE"1 CHAR"RESET);
	fd = open("1char", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"1 CHAR - CALL TWICE"RESET);
	fd = open("1char", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"1 CHAR WITH NL"RESET);
	fd = open("1char_with_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"1 CHAR WITH NL- CALL TWICE"RESET);
	fd = open("1char_with_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"EMPTY TWICE"RESET);
	fd = open("empty", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"ONLY NL"RESET);
	fd = open("newline", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"ONLY NL - TWICE"RESET);
	fd = open("newline", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT NO NL"RESET);
	fd = open("no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	close(fd);
	puts("\n");
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT NO NL - TWICE"RESET);
	fd = open("no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT WITH NL"RESET);
	fd = open("with_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	close(fd);
	puts("\n");
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT WITH NL - TWICE"RESET);
	fd = open("with_nl", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT WITH 1CHAR 2ND LINE"RESET);
	fd = open("with_nl_1char", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	close(fd);
	puts("\n");
	puts(BG_BRIGHT_WHITE BOLD BLUE"TEXT WITH 1CHAR 2ND LINE - 3TIMES"RESET);
	fd = open("with_nl_1char", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"1CHAR TXT 2ND LINE"RESET);
	fd = open("1char_txt", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	close(fd);
	puts("\n");
	puts(BG_BRIGHT_WHITE BOLD BLUE"1CHAR TXT 2ND LINE - 3TIMES"RESET);
	fd = open("1char_txt", O_RDONLY);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf(GREEN "Test %u- "RESET, i++);
	printf("%s", line);
	free (line);
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"1CHAR TXT 2ND LINE"RESET);
	fd = open("big_txt", O_RDONLY);
	j = 0;
	while(j < 100)
	{
		line = get_next_line(fd);
		printf(GREEN "Test %u- "RESET, i++);
		printf("%s", line);
		free (line);
		j++;
	}
	puts("\n");
	close(fd);
	puts(BG_BRIGHT_WHITE BOLD BLUE"MULTI FD"RESET);
	j = 0;
	fd = open("bonus", O_RDONLY);
	fd1 = open("bonus1", O_RDONLY);
	fd2 = open("bonus2", O_RDONLY);
	fd3 = open("bonus3", O_RDONLY);
	while (j <= 4)
	{
		line = get_next_line(fd);
		printf(MAGENTA"FD %d- ", fd);
		printf(GREEN "Test %u- "RESET, i++);
		printf("%s", line);
		free (line);
		puts("");
		line = get_next_line(fd1);
		printf(MAGENTA"FD %d- ", fd1);
		printf(GREEN "Test %u- "RESET, i++);
		printf("%s", line);
		free (line);
		puts("");
		line = get_next_line(fd2);
		printf(MAGENTA"FD %d- ", fd2);
		printf(GREEN "Test %u- "RESET, i++);
		printf("%s", line);
		free (line);
		puts("");
		line = get_next_line(fd3);
		printf(MAGENTA"FD %d- ", fd3);
		printf(GREEN "Test %u- "RESET, i++);
		printf("%s", line);
		free (line);
		puts("");
		j++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}
