/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:22:30 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/03 15:41:16 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	search_str;
	size_t			i;

	str = (unsigned char *)s;
	search_str = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == search_str)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}
