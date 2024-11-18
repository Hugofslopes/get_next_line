/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:10:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/18 21:49:44 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		copy_fd(int fd, char **strgs);
void	add_to_strgs(char *buffer, char ***strgs);
char	*verify_newline(char **strgs);
char	*realloc_strgs(char *strgs, size_t len);
char	*trim_strgs(char *strgs, size_t len, size_t i);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*alloc_for_nl(size_t j, size_t len, char **strgs);
#endif