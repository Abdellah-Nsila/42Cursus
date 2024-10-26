/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/10/26 09:24:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ptr = b;
	ch = c;
	while (i < len)
		ptr[i++] = ch;
	return (b);
}
