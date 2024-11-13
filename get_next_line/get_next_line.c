/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:55:16 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/13 15:22:20 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return ;
	clean_node = ft_calloc(sizeof(t_list), 1);
	if (!clean_node)
	{
    free(buffer);
    return ;
	}
	i = 0;
	j = 0;
	last_node = ft_lstlast(*list);
	while (last_node->str_buffer[i] != '\0' && last_node->str_buffer[i] != \
	'\n')
		i++;
	while (last_node->str_buffer[i] != '\0' && last_node->str_buffer[i])
		buffer[j++] = last_node->str_buffer[i++];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	clean_list(list, clean_node, buffer);
}

char	*get_new_line(t_list *list)
{
	size_t	str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = get_newline_len(list);
	next_str = ft_calloc(str_len + 1, sizeof(char));
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	copy_str(t_list *list, char *str)
{
	size_t	i;
	size_t	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	add_to_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = ft_calloc(sizeof(t_list), 1);
	if (!new_node)
	{
		free(buf);
		return ;
	}
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buf;
	new_node->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	int				char_read;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (!find_newline(list))
	{
		buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read < 0)
			return (free(buffer), NULL);
		buffer[char_read] = '\0';
		add_to_list(&list, buffer);
		if (char_read == 0)
		{
			break ;
			return (NULL);
		}
	}
	next_line = get_new_line(list);
	prepare_list(&list);
	return (next_line);
}
