/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:27:36 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 16:05:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(unsigned long n)
{
    int len;

    len = 0;
    len += ft_print_str("0x");
    len += ft_print_hexa(n, "0123456789abcdef");
    return (len);
}
