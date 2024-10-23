/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:12:03 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/23 09:51:54 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
void	*ft_memset(void *ptr, int x, size_t n);
void	ft_bzero(void *s, size_t n);

int ft_toupper(int c);
int ft_tolower(int c);
char	*ft_strchr(const char *str, int search_str);


#endif
