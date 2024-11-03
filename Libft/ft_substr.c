/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:07:42 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/03 17:59:15 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			src_len;
	size_t			substr_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	substr_len = src_len - start;
	if (substr_len > len)
		substr_len = len;
	ptr = (char *) malloc(substr_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s[start], substr_len + 1);
	return ((char *)ptr);
}
