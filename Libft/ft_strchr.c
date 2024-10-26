/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:27:05 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/26 09:05:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	search_str;
	int				i;

	search_str = c;
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
