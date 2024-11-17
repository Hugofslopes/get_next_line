/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:49:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/17 14:39:03 by hfilipe-         ###   ########.fr       */
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

char	*get_next_line(int fd);
int		find_newline(char *strgs);
char	*copy_str(char *str, char *new_str);
size_t	ft_strlen(const char *str);
void	add_to_strgs(char **strgs, char *buffer, char **next_line, size_t *i);
char	*ft_realloc(char *next_line, size_t new_size, char ***strgs);
char	*ft_memcoppy(char *dst, char *src, char *strgs);
void	*ft_calloc(size_t nmemb, size_t size);
void	save_strgs(char ***next_string, char *buffer, char ***strgs, size_t *i);
char *handle_strgs (char *dst, char *strgs);
#endif