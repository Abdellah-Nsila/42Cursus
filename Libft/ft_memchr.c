/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:22:30 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/25 15:19:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned char	search_str;
	size_t			i;

	str = (char *)s;
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
