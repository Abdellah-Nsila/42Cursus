/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:02:49 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/01 18:06:11 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	ft_putstr_fd(s, fd);
}

int	main()
{
	int	n;
	int	fd;

	n = -2024;
	fd = open("./Test/t.txt", O_WRONLY);
	if (fd == -1)
		return (0);
	ft_putnbr_fd(n, fd);
	return (1);
}