/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:06:52 by abnsila           #+#    #+#             */
/*   Updated: 2024/11/01 17:55:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int	main()
{
	char	*s;
	int		fd;

	s = "Abdellah Nsila";
	fd = open("./Test/t.txt", O_WRONLY);
	if (fd == -1)
		return (0);
	ft_putstr_fd(s, fd);
	return (1);
}