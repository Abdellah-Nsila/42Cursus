/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:36 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/08 18:31:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;
// 	size_t				i;

// 	if (!dst && !src)
// 		return (NULL);
// 	if (dst == src)
// 		return (dst);
// 	d = (unsigned char *)dst;
// 	s = (const unsigned char *)src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dst);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main()
// {
// 	char	src[] = "Hello World";
// 	char	dst[20];
	
// 	printf("Dst: %s\n", (char *)memcpy(src + 3, src, 5));
// 	printf("Src: %s\n", src);
// 	printf("Dst: %s\n", (char *)ft_memcpy(src, src, -1));
// }
