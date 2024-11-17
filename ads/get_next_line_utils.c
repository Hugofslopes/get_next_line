/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:34:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/17 18:48:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		i++;
		if (*str++ == '\n')
			return (i);
	}
	return (i);
}

int	find_newline(char *next_line)
{
	size_t	i = 0;

	if (!next_line)
		return (0);
	while (next_line[i] || i < BUFFER_SIZE)
	{
		if (next_line[i++] == '\n')
			return (1);
	}
	return (0);
}

char *handle_strgs (char *dst, char *strgs)
{
	size_t	i;

	i = 0;
	while (strgs[i])
	{
		dst[i] = strgs[i];
		if (dst[i++] == '\n')
		{
			dst[i] = '\0';
			i--;
			while (strgs[i])
			{
				strgs [i] = strgs[i + 1];
				i++;
			}
			i--;
			strgs[i] = '\0';
			return (dst);
		}
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_memcoppy(char *new_ptr, char *next_line, char *strgs)
{
	unsigned int	i;

	i = 0;
	if (strgs != NULL)
	{
		new_ptr = handle_strgs(new_ptr, strgs);
		return(new_ptr);
	}
	if (next_line != NULL)
	{
		while (next_line[i])
		{
			new_ptr[i] = next_line[i];
			i++;
		}
		next_line[i] = '\0';
		return (new_ptr);
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_bytes;
	size_t	i;
	char	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_bytes = nmemb * size;
	if ((total_bytes / size) != nmemb)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	str = (char *)ptr;
	while (i < total_bytes)
		str[i++] = '\0';
	return (ptr);
}
