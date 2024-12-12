/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:44:28 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/12 15:52:43 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search_str;
	size_t			i;

	search_str = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == search_str)
			return ((char *)(&str[i]));
		i++;
	}
	if (search_str == '\0')
		return ((char *)(&str[i]));
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	if (!dst && !src && dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (((dst_len + i) < (dstsize - 1)) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen((char *)s1) + 1;
	dst = (char *) malloc(src_len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, src_len);
	return (dst);
}

char	*ft_clean(char **static_var)
{
	free(*static_var);
	*static_var = NULL;
	return (NULL);
}
