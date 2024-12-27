/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:36:25 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/27 17:38:37 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long result = 0;
	int sign = 1;
	long digit;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+') {
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9') {
		digit = *str - '0';
		if (result > (LONG_MAX - digit) / 10) {
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}
