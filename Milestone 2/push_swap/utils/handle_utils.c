/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:48:02 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 19:14:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*generate_stack(char **arr, int size)
{
	t_stack	*head;
	t_stack	*new_node;

	head = NULL;
	while (size--)
	{
		new_node = new(ft_atoi(arr[size]));
		if (!new_node)
			return (NULL);
		push(&head, new_node);
	}
	return (head);
}

int	ft_check_is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->next == stack)
			break;
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_execute_single_stack(t_stack **s, int t, int f, const char *c)
{
	if (t == SA || t == SB)
		sa_sb(s);
	else if (t == RA || t == RB || t == RRA || t == RRB)
		ra_rb_rra_rrb(s, t);
	if (f)
		ft_printf("%s\n", c);
}

void	ft_execute_dual_stack(t_command *cmd)
{
	if (cmd->type == PA)
		pa_pb(cmd->a, cmd->b);
	else if (cmd->type == PB)
		pa_pb(cmd->b, cmd->a);
	else if (cmd->type == RR || cmd->type == RRR)
		rr_rrr(cmd->a, cmd->b, cmd->type);
	if (cmd->flag)
		ft_printf("%s\n", cmd->command);
}

//TODO i nedd to fix norminette
void	ft_execute_command(t_stack **a, t_stack **b, int type, int flag)
{
	t_command cmd;
	const char *commands[10];

	commands[SA] = "sa";
	commands[SB] = "sb";
	commands[PA] = "pa";
	commands[PB] = "pb";
	commands[RA] = "ra";
	commands[RB] = "rb";
	commands[RRA] = "rra";
	commands[RRB] = "rrb";
	commands[RR] = "rr";
	commands[RRR] = "rrr";
	cmd.a = a;
	cmd.b = b;
	cmd.type = type;
	cmd.flag = flag;
	cmd.command = commands[type];
	if (type == SA || type == SB || type == RA || type == RB || type == RRA || type == RRB)
	{
		ft_execute_single_stack((type == SA || type == RA || type == RRA) ? a : b,
								type, flag, commands[type]);
	}
	else
		ft_execute_dual_stack(&cmd);
}
