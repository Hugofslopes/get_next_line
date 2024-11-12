/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:55:16 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/12 16:58:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (-1);
	clean_node = malloc(sizeof(t_list));
	if (!buffer)
		return (-1);
	i = 0;
	j = 0;
	last_node = ft_lstlast(*list);
	while (last_node->str_buffer[i] != '\0' && last_node->str_buffer[i] != \
	'\n')
		i++;
	while (last_node->str_buffer[i] != '\0' && last_node->str_buffer[i++])
		buffer[j++] = last_node->str_buffer[i];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	clean_list(list, clean_node, buffer);
	return (0);
}

char	*get_new_line(t_list *list)
{
	size_t	str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = get_newline_len(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

int	add_to_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (-1);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buf;
	new_node->next = NULL;
	return (0);
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!find_newline(*list))
	{
		buffer = malloc (BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free (buffer);
			return (-1);
		}
		buffer[char_read] = '\0';
		add_to_list(list, buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_new_line(list);
	prepare_list(&list);
	return (next_line);
}
