/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:51:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/17 23:44:24 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{	
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *realloc_strgs(char *strgs, size_t len)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = malloc((len + 1) * sizeof(char));
	if (!new_ptr)
		return (NULL);
	i = 0;
	if(strgs != NULL)
	{
		while(strgs[i])
		{
			new_ptr[i] = strgs[i];
			i++;
		}
		free(strgs);
		new_ptr[i] = '\0';
	}
	return (new_ptr);
}

/* void	verify_newline(char **strgs, char **next_line, size_t *i)
{
	size_t	len;
	
	while(**strgs != '\n')
	{
		(*next_line)[(*i)] = **strgs++;
		if ((*next_line)[(*i)++] == '\n')
			break;
	}
	len = ft_strlen(*strgs);
	*strgs = realloc_strgs(&strgs, len);
} */

void	add_to_strgs(char *buffer, char ***strgs, size_t *i)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char 	*temp;
	size_t 	j;

	if (**strgs == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(**strgs);
	if (!buffer)
		len2 = 0;
	else
		len2 = ft_strlen(buffer);
	total_len = len1 + len2;
	temp = realloc_strgs(**strgs, total_len);
	**strgs = temp;
	j = 0;
	while (buffer[j])
	{
		temp[len1 + (*i)] = buffer[j];
		(*i)++;
		j++;
	}
	temp[len1 + (*i)] = '\0';
	free(buffer);
}

void	copy_fd(int fd, char **strgs)
{
	char			*buffer;
	int				char_readed;
	static size_t	i = 0;

	char_readed = 1;
	while (char_readed > 0)
	{
	buffer = NULL;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buffer)
			return ;
	char_readed = read(fd, buffer, BUFFER_SIZE);
		if (char_readed < 0)
		return ;	
	add_to_strgs(buffer, &strgs, &i);
	}
}

char	*get_next_line(int fd)
{
	static char		*strgs = NULL;
	char			*next_line;
	static size_t	i = 0;

	if( fd < 0 || BUFFER_SIZE <0)
		return 0;
	copy_fd(fd, &strgs);
	// verify_newline (&strgs, &next_line, &i);
	return (next_line);
}
