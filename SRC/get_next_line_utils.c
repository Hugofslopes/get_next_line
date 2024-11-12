/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:20:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/12 12:56:03 by hfilipe-         ###   ########.fr       */
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
		return (-1);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
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

void	clean_list(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*tmp;

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
		*list = clean_node;
	else
	{
		free (buffer);
		free (clean_node);
	}
}
