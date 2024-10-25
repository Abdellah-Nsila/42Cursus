/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:07:42 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/25 16:23:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{	
		j = 0;
		while (needle[j] && j < len)
		{
			if (haystack[i + j] != needle[j])
				break;
			j++;
		}
		i++;
	}
	
}