/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:49:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/14 21:41:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		find_newline(char *strgs, size_t *counter);
char	*get_new_line(char *str);
char	*copy_str(char *str, char *new_str);
size_t	ft_strlen(const char *str);
char	*add_to_strgs(char *strgs, char const *buffer, size_t counter);
char 	*ft_realloc(char *ptr, size_t new_size);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif