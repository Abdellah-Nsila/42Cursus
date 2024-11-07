/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/07 17:21:32 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

// int	main()
// {
//	char  str[] = "Hello World";
//	int arr[2] = {777, 42};
//	char  *p1 = (char *)&arr[0];
//	char  *p2 = (char *)&arr[1];
//	ft_memset(str + 4, 0b00100011, 1);
//	ft_memset(p1, 57, 1);
//	ft_memset(p1 + 1, 5, 1);
//	ft_memset(p2, 0b11000111, 1);
//	ft_memset(p2 + 1, 0b11111010, 1);
//	ft_memset(p2 + 2, 255, 1);
//	ft_memset(p2 + 3, 255, 1);
//	return (1);
// }
