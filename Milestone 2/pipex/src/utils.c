/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/07 15:54:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	ft_printnums(int n)
{
	int i;

	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
}

int	power(int n, int power)
{
	int res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

int	ft_n_sum(int *arr, int start, int size)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < size)
	{
		s += arr[start + i];
		i++;
	}
	return (s);
}