/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:52:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/15 15:21:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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

char	*get_new_line(char *str)
{
	size_t	str_len;
	char	*next_str;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	next_str = ft_calloc(str_len + 1, sizeof(char));
	if (!next_str)
		return (NULL);
	next_str = copy_str(str, next_str);
	return (next_str);
}

char	*add_to_strgs(char *strgs, char const *buffer)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	static char 	*temp = NULL;

	result = NULL;
	if (strgs == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(strgs);
	len2 = ft_strlen(buffer);
	result = ft_realloc(strgs, (len1 + len2));
	if (!result)
		return (NULL);
	result = save_strgs(result, (char *)buffer, &temp);
	return(result);
}

char *save_strgs(char *result , char *buffer, char **temp)
{
	static size_t	i = 0;
	size_t		j;
	
	
	j = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
		{
			result[i++] = '\n';
			if (ft_strlen(++buffer) > 0)
			{
				*temp = ft_calloc(ft_strlen(buffer) + 1 , sizeof(char));
			while (*buffer)
				*temp[j] = *buffer++;
			*temp[j] = '\0';
			}	
			break ;
		}
		result[i++] = *buffer++;
	}
	result[i] = '\0';
	return(result);
}

char	*get_next_line(int fd)
{
	static char		*strgs = NULL;
	char			*next_line;
	int				char_readed;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 2 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (!find_newline(strgs))
	{
		buffer = NULL;
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		char_readed = read(fd, buffer, BUFFER_SIZE);
		if (char_readed <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[char_readed] = '\0';
		strgs = add_to_strgs(strgs, buffer);
		free(buffer);
	}
	next_line = get_new_line(strgs);
	//free(strgs);
	return (next_line);
}