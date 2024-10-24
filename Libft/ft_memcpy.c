/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:36 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/24 10:23:28 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s == NULL || d == NULL)
		return (dst);
	while(i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
