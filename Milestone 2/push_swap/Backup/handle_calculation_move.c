#include "push_swap.h"

int	ft_calculate_rotate(t_stack *stack, int index)
{
	int size;
	int half;

	size = stack_size(stack);
	half = size / 2;
	if (index <= half)
		return (index);
	return (index - size);
}

int	ft_calculate_top_max(t_stack *stack, int max)
{
	int	index;

	index = ft_find_index(stack, max);
	return (ft_calculate_rotate(stack, index));
}

int	ft_calculate_b_rotate(t_stack *stack, int n)
{
	t_stack	*current;
	int		index;
	int		min;
	int		max;

	current = stack;
	index = 0;
	min = ft_find_min(stack);
	max = ft_find_max(stack);
	if (n < min || n > max)
		return (ft_calculate_top_max(stack, max));
	while (current)
	{
		// printf("prev: %d,  current: %d\n", current->prev->n, current->n);
		// printf("Cond: %d, index: %d\n", current->prev->n > n && current->n < n, index);
		if (current->prev->n > n && current->n < n)
			break;
		current = current->next;
		index++;
	}
	return (ft_calculate_rotate(stack, index));
}

t_command	ft_calculate_command(t_stack *a, int index, t_stack *b, int n)
{
	t_command command;

	command.n = n;
	command.index = index;
	command.a_rotate = ft_calculate_rotate(a, index);
	command.b_rotate = ft_calculate_b_rotate(b, n);

	if (command.a_rotate * command.b_rotate > 0)
	{
		if (ABS(command.a_rotate) > ABS(command.b_rotate))
			command.cost = ABS(command.a_rotate);
		else
			command.cost = ABS(command.b_rotate);
	}
	else
		command.cost = ABS(command.a_rotate) + ABS(command.b_rotate);
	return command;
}