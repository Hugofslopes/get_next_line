/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:01 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/12 16:26:57 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
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
int		add_to_list(t_list **list, char *buf);
int		create_list(t_list **list, int fd);
#endif