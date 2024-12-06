/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:27:36 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 16:10:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(unsigned long n)
{
    if ((void *)n == NULL)
        return (ft_print_str("(nil)"));
    return (ft_print_str("0x") + ft_print_hexa(n, "0123456789abcdef"));
}
