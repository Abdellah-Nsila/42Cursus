/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:47:21 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/27 20:05:19 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*ptr;
	
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_size = (strlen(s1) + strlen(s2)) + 1;
	ptr = (char *) malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	_ft_strlcpy(ptr, s1, total_size);
	_ft_strlcat(ptr, s2, total_size);
	return (ptr);
}
