/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:49:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/13 14:03:32 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		find_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
size_t	get_newline_len(t_list *list);
void	copy_str(t_list *list, char *str);
void	clean_list(t_list **list, t_list *clean_node, char *buffer);
void	prepare_list(t_list **list);
char	*get_new_line(t_list *list);
void	add_to_list(t_list **list, char *buf);
void	*ft_calloc(size_t nmemb, size_t size);
#endif