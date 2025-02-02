/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:44:54 by abnsila           #+#    #+#             */
/*   Updated: 2025/02/02 12:06:13 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_bool	ft_strlcmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n) == 0
		&& ft_strlen(s1) == n)
	{
		return (true);
	}
	return (false);
}
