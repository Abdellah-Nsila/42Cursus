/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:07:41 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/10 00:32:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkchr(const char *set, int c)
{
	unsigned char	search_set;
	int				i;

	search_set = c;
	i = 0;
	while (set[i])
	{
		if (set[i] == search_set)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start_index;
	int		end_index;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (s1[start_index] && ft_checkchr(set, s1[start_index]))
		start_index++;
	end_index = ft_strlen(s1) - 1;
	while (end_index >= start_index && ft_checkchr(set, s1[end_index]))
		end_index--;
	ptr = (char *) malloc((end_index - start_index + 1) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start_index + i <= end_index)
	{
		ptr[i] = s1[start_index + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
