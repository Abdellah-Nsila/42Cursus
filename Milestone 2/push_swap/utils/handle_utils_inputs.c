/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils_inputs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:46:22 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 18:47:42 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_is_valid_number(char *str)
{
	long	num;

	if (!ft_isnumber(str))
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	ft_has_duplicates(char **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atol(arr[i]) == ft_atol(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate_arg(char **arr, int size)
{
	int	i;

	if (size <= 0)
		return (1);
	i = 0;
	while (i < size)
	{
		if (!ft_is_valid_number(arr[i]))
			return (0);
		i++;
	}
	return (!ft_has_duplicates(arr, size));
}
