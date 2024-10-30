/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:10:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/30 12:25:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void ft_storeint(char *ptr, int n, int index, int sign)
{
	if (index >= sign)
	{
		if (n > 9)
		{
			ft_storeint(ptr, (n / 10), (index - 1), sign);
			ptr[index] = (n % 10) + 48;
		}
		ptr[index] = (n % 10) + 48;
	}
}

static int	ft_getlen(int n)
{
	if (n > 9)
		return(1 + ft_getlen(n / 10));
	return (1);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*ptr;

	len = 0;
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;	
	}
	len = sign + ft_getlen(n);
	ptr = (char *) malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_storeint(ptr, n, len - 1, sign);
	if (sign)
		ptr[0] = '-';
	ptr[len + 1] = '\0';
	return (ptr);
}

// int	main()
// {
// 	int	n = 2147483647;
// 	char	*str;
	
// 	str = ft_itoa(n);
// 	printf("\nft_itoa(%ld) Num: %s\n\n", n, str);
	
// 	free(str);
// 	return (0);
// }