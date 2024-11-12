/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/12 15:45:44 by hfilipe-         ###   ########.fr       */
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
	//fd = open("/home/hfilipe-/42/get_next_line/test/test.txt", O_RDONLY);
	fd = open("test.txt",O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Test%u- %s", i++, line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
