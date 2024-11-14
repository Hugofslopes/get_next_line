/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:55:16 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/14 17:50:23 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	clean_node = ft_calloc(sizeof(t_list), 1);
	if (!clean_node || !buf)
		return (free (buf));
	i = 0;
	j = 0;
	last_node = ft_lstlast(*list);
	if (!last_node)
		return (free(buf), free(clean_node));
	while (last_node->str_buffer[i] != '\0' && last_node->str_buffer[i] != \
	'\n')
		i++;
	while (last_node->str_buffer[i++])
		buf[j++] = last_node->str_buffer[i];
	buf[j] = '\0';
	clean_node->str_buffer = buf;
	clean_node->next = NULL;
	clean_list(list, clean_node, buf);
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

void	add_to_list(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = ft_calloc(sizeof(t_list), 1);
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	int				char_readed;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 2 || read(fd, &next_line, 0) < 0)
		return (NULL);
	while (!find_newline(list))
	{
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
		add_to_list(&list, buffer);
	}
	next_line = get_new_line(list);
	prepare_list(&list);
	return (next_line);
}
