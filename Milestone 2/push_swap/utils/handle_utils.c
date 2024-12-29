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

void	ft_execute_single_stack(t_stack **stack, int type, int flag, const char *command)
{
	if (type == SA || type == SB)
		sa_sb(stack);
	else if (type == RA || type == RB)
		ra_rb_rra_rrb(stack, type);
	else if (type == RRA || type == RRB)
		ra_rb_rra_rrb(stack, type);
	if (flag)
		ft_printf("%s\n", command);
}

void	ft_execute_dual_stack(t_stack **a, t_stack **b, int type, int flag, const char *command)
{
	if (type == PA)
		pa_pb(a, b);
	else if (type == PB)
		pa_pb(b, a);
	else if (type == RR || type == RRR)
		rr_rrr(a, b, type);
	if (flag)
		ft_printf("%s\n", command);
}

void	ft_execute_command(t_stack **a, t_stack **b, int type, int flag)
{
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

	if (type == SA || type == SB || type == RA || type == RB || type == RRA || type == RRB)
		ft_execute_single_stack((type == SA || type == RA || type == RRA) ? a : b, type, flag, commands[type]);
	else if (type == PA || type == PB || type == RR || type == RRR)
		ft_execute_dual_stack(a, b, type, flag, commands[type]);
}
