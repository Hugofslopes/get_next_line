/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/19 11:14:38 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "colors.h"

int	main(void)
{
	int				fd;
	char			*line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
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
	return (0);
}
