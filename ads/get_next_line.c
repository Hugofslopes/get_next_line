/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:52:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/17 19:30:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_str(char *str, char *new_str)
{
	size_t	i;

	if (!str || !new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		if (str[i] == '\n')
		{
			new_str[i++] = '\n';
			new_str[i] = '\0';
			return (new_str);
		}
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	save_strgs(char ***next_line, char *buffer, char ***strgs, size_t *i)
{
	size_t	j;

	if (buffer == NULL)
		return ;
	j = 0;
	while (*buffer)
	{
		if (*buffer == '\n' || **next_line[0] == '\n')
		{
			(**next_line)[(*i)++] = '\n';
			if (ft_strlen(++buffer) > 0)
			{
				**strgs = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));
				if (**strgs == NULL)
					return ;
				while (*buffer)
					(**strgs)[j++] = *buffer++;
				(**strgs)[j] = '\0';
			}
			else if (ft_strlen(**strgs) > 0)
				return ;
			break ;
		}
		(**next_line)[(*i)++] = *buffer++;
	}
	(**next_line)[(*i)] = '\0';
}

char	*ft_realloc(char *next_line, size_t size, char ***strgs)
{
	char	*new_ptr;

	new_ptr = ft_calloc(size + 1, sizeof(char));
	if (!new_ptr)
		return (NULL);
	if (next_line == NULL && **strgs == NULL)
		return (new_ptr);
	new_ptr = ft_memcoppy(new_ptr, next_line, **strgs);
	if (**strgs != NULL)
	{
		if ((**strgs)[0] != '\0' && (**strgs)[0] != '\n' && new_ptr[0] != '\n')
		{
			free(**strgs);
			**strgs = NULL;
		}	
	}
	free(next_line);
	return (new_ptr);
}

void	add_to_strgs(char **strgs, char *buffer, char **next_line, size_t *i)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;

	if (*strgs == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(*strgs);
	if (*next_line == NULL)
		len3 = 0;
	else
		len3 = ft_strlen(*next_line);
	len2 = ft_strlen(buffer);
	*next_line = ft_realloc(*next_line, (len1 + len2 + len3), &strgs);
	save_strgs(&next_line, buffer, &strgs, i);
}

char	*get_next_line(int fd)
{
	static char		*strgs = NULL;
	char			*next_line;
	int				char_readed;
	char			*buffer;
	static size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	i = ft_strlen(strgs);
	next_line = NULL;
	while (!find_newline(next_line))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		char_readed = read(fd, buffer, BUFFER_SIZE);
		if (char_readed <= 0 && strgs == NULL)
		{
			free(buffer);
			break ;
		}
		buffer[char_readed] = '\0';
		add_to_strgs(&strgs, buffer, &next_line, &i);
		free(buffer);
	}
	return (next_line);
}
