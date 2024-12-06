/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:28:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/06 12:11:39 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_nbr(int n)
{
	if (n == -2147483648)
		ft_print_str("-2147483648");
	else if (n < 0)
	{
		ft_print_char('-');
		n = -n;
		ft_print_nbr(n);
	}
	else if (n > 9)
	{
		ft_print_nbr(n / 10);
		ft_print_nbr(n % 10);
	}
	else
	{
		ft_print_char(n + '0');
	}
}


int main()
{
    ft_print_nbr(1337);
}