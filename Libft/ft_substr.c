/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:07:42 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/27 17:43:29 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			src_len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		len = 0;
	ptr = (char *) malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	ft_strlcpy(ptr, &s[start], len + 1);
	return ((char *)ptr);
}
