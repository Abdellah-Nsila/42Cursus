/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_perfect_chipset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:12:12 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 18:36:05 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_run_perfect_rotation(t_stack **a, t_stack **b, int x_rot, int stack)
{
	if (x_rot > 0)
		while (x_rot-- > 0)
			ft_execute_command(a, b, RA + stack, 1);
	else if (x_rot < 0)
	{
		x_rot = ABS(x_rot);
		while (x_rot-- > 0)
			ft_execute_command(a, b, RRA + stack, 1);
	}
}

void	ft_run_perfect_command(t_stack **a, t_stack **b, t_chipset command)
{
	int	type;

	if (command.a_rotate * command.b_rotate > 0)
	{
		if (command.a_rotate > 0)
			type = RR;
		else
			type = RRR;
		while (command.a_rotate && command.b_rotate)
		{
			ft_execute_command(a, b, type, 1);
			command.a_rotate -= 1 * ((command.a_rotate >= 0) * 2 - 1);
			command.b_rotate -= 1 * ((command.b_rotate >= 0) * 2 - 1);
		}
	}
	if (command.a_rotate != 0)
		ft_run_perfect_rotation(a, b, command.a_rotate, STACK_A);
	if (command.b_rotate != 0)
		ft_run_perfect_rotation(a, b, command.b_rotate, STACK_B);
	ft_execute_command(a, b, PB, 1);
}

t_chipset	ft_get_perfect_chipset(t_stack *a, t_stack *b)
{
	t_stack		*current;
	int			index;
	int			n;
	t_chipset	chipset;
	t_chipset	perfect_chipset;

	current = a;
	index = 0;
	perfect_chipset.cost = INT_MAX;
	while (current)
	{
		n = current->n;
		chipset = ft_calculate_command(a, index, b, n);
		if (chipset.cost < perfect_chipset.cost)
			perfect_chipset = chipset;
		current = current->next;
		index++;
		if (current == a || perfect_chipset.cost == 0)
			break ;
	}
	return (perfect_chipset);
}
