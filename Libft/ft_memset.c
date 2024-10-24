/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/24 14:04:14 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <string.h>
void	*ft_memset(void *ptr, char x, size_t n)
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
