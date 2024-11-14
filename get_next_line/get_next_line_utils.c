/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:20:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/14 17:52:23 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_list;

	tmp_list = lst;
	if (!lst)
		return (NULL);
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	return (tmp_list);
}

size_t	get_newline_len(t_list *list)
{
	size_t	i;
	size_t	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	clean_list(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

(void)buf;
	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free ((*list)->str_buffer);
		free (*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0])
	{
		*list = clean_node;
		free(buf);
		free(clean_node);
	}
	else
	{
		free(buf);
		free(clean_node);
	}
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
