/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:48:20 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 11:53:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int ft_print_char(int c);
int ft_print_str(char *s);
int ft_print_nbr(int n);
int ft_print_hexa(int n, char *base);
int ft_print_ptr(unsigned int n);
int ft_print_unsigned_nbr(unsigned int n);

#endif
