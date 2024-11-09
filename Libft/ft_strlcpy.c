/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:41:39 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/09 19:20:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0 || dst == NULL)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <bsd/string.h>

// int	main()
// {
// 	char	src[] = "Hello World";
// 	char	dst[20];

// 	printf("Dst: %s\n", ft_strlcpy(dst, src, 4));
// 	printf("Dst: %s\n", src);
// 	printf("Src: %s\n", src);
// }
