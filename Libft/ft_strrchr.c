/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:34:27 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/23 14:41:58 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t _ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrchr( const char *str, int c)
{
	unsigned char	search_str;
	int	len;
	
	search_str = c;
	len = _ft_strlen((char *)str);
	while (len >= 0)
	{
		if (str[len] == search_str)
			return ((char *)(&str[len]));
		len--;
	}
	return (NULL);
}