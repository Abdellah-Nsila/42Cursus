/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:29:30 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/13 15:30:38 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);

size_t	ft_strlen(char	*s);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_clean(char **static_var);

char	*ft_append_buff(char **static_var, char *buff, ssize_t rb);
char	*ft_get_remaining(char **static_var, char *end_line);
char	*ft_get_line(char **static_var, char *end_line);
char	*ft_handle_end_of_read(char **static_var, char *buff, ssize_t rb);

#endif