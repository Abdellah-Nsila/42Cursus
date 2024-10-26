/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:02:15 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/26 14:40:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen(s1);
	dst = (char *) malloc(src_len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, src_len + 1);
	return ((char *)dst);
}
