/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:08:28 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 18:08:49 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_two(t_stack **a)
{
	if ((*a)->n > (*a)->next->n)
		ft_execute_command(a, NULL, SA, 1);
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
		&& (*a)->n > (*a)->next->next->n)
		ft_execute_command(a, NULL, RA, 1);
	else
	{
		while ((*a)->n > (*a)->next->n || (*a)->next->n > (*a)->next->next->n)
		{
			if ((*a)->n > (*a)->next->n)
				ft_execute_command(a, NULL, SA, 1);
			if ((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
				break ;
			if ((*a)->next->n > (*a)->next->next->n)
				ft_execute_command(a, NULL, RRA, 1);
		}
	}
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	ft_execute_command(a, b, PB, 1);
	ft_sort_three(a);
	ft_push_back(a, b);
}
