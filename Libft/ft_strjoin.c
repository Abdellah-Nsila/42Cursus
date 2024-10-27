/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:47:21 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/27 18:51:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


size_t	_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == NULL)
		return (0);
	src_len = strlen(src);
	if (dstsize == 0 || dst == NULL)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		printf("cpy: %c\t", src[i]);
		i++;
	}
	dst[i] = '\0';
	printf("\n");
	return (src_len);
}

size_t	_ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (((dst_len + i) < (dstsize - 1)) && src[i])
	{
		dst[dst_len + i] = src[i];
		printf("cat: %c\t", src[i]);
		i++;
	}
	dst[dst_len + i] = '\0';
	printf("\n");
	return (src_len + dst_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*ptr;
	
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_size = (strlen(s1) + strlen(s2)) + 1;
	ptr = (char *) malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	_ft_strlcpy(ptr, s1, total_size);
	_ft_strlcat(ptr, s2, total_size);
	return (ptr);
}


int	main(int ac, char **av)
{
	char	*res; 
	if (ac != 3)
		return (0);
		
	res = ft_strjoin((char const *)av[1], (char const *)av[2]);
	printf("Result: %s\n", res);
	free(res);

	res = ft_strjoin((char const *)"Hi\n", (char const *)av[2]);
	printf("Result: %s\n", res);
	free(res);
}
