/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/13 21:44:18 by hfilipe-         ###   ########.fr       */
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
	//fd = open("test.txt", O_RDONLY);
	fd = open("test.txt",O_RDONLY);
	printf("%i\n",fd);
	line = get_next_line(fd);
	printf("Test%u- %s", i++, line);
		free (line);

	line = get_next_line(2);
	printf("Test%u- %s", i++, line);
		free (line);

	line = get_next_line(0);
	printf("Test%u- %s", i++, line);
		free (line);
		
	line = get_next_line(1);
	printf("Test%u- %s", i++, line);
		free (line);
/* 	while (line != NULL)
	{
		printf("Test%u- %s", i++, line);
		free (line);
		line = get_next_line(fd);
	} */
	close(fd);
	return (0);
}
