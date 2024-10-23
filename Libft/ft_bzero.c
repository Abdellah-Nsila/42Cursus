/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:50:09 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/23 10:31:24 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO[ ] We should compile all files ,before use the ft_memset without recoded here 

static void	*_ft_memset(void *ptr, int x, size_t n)
{
	char	*p;
	unsigned char	c;
	size_t	i;

	i = 0;
	p = ptr;
	c = x;
	while (i < n)
		p[i++] = c;
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	_ft_memset(s, 0, n);
}
