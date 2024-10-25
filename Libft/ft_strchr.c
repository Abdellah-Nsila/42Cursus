/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:27:05 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/25 15:00:20 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char search_str = c;
	int i;

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
