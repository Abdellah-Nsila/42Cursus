/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:34:27 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/26 09:23:40 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *str, int c)
{
	unsigned char	search_str;
	int				len;

	search_str = c;
	len = ft_strlen((char *)str);
	while (len >= 0)
	{
		if (str[len] == search_str)
			return ((char *)(&str[len]));
		len--;
	}
	return (NULL);
}
