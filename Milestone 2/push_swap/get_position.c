#include "push_swap.h"

int	ft_find_index(t_stack *stack, int max)
{
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (current)
	{
		if (current->n == max)
			break;
		current = current->next;
		index++;
	}
	return (index);
}

int	ft_find_max(t_stack *stack)
{
	t_stack *current;
	int		max;

	current = stack;
	max = current->n;
	while (current)
	{
		if (current->n > max)
			max = current->n;
		current = current->next;
		if (current == stack)
			break;
	}
	return (max);
}

int	ft_find_min(t_stack *stack)
{
	t_stack *current;
	int     min;

	current = stack;
	min = current->n;
	while (current)
	{
		if (current->n < min)
			min = current->n;
		current = current->next;
		if (current == stack)
			break;
	}
	return (min);
}
