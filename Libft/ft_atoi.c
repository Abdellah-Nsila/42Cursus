/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:33:43 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/06 15:35:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					num;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit((int)str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (0);
// 	printf("Num: %d\n", ft_atoi(av[1]));
//	return (1);
// }
