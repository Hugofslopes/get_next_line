/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/12 16:38:13 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int				fd;
	char			*line;
	unsigned int	i;

	i = 0;

	fd = open("test.txt",O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Test%u- %s", i++, line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);

	fd = open("test.txt",O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Test%u- %s", i++, line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);

	fd = open("test1.txt",O_RDONLY);
	line = get_next_line(fd);
	printf("Test%u- %s", i++, line);
	free (line);
	line = get_next_line(fd);
	printf("Test%u- %s", i++, line);
	free (line);
	close(fd);

	fd = open("test1.txt",O_RDONLY);
	line = get_next_line(fd);
	printf("Test%u- %s", i++, line);
	free (line);
	close(fd);


	return (0);
}
