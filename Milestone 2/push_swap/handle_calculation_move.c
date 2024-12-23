#include "push_swap.h"

int	ft_calculate_a_rotate(t_stack *stack, int index)
{
	int size;
	int half;

	size = stack_size(stack);
	half = size / 2;
	if (index <= half)
		return (index);
	return (index - size);
}

int	ft_calculate_b_rotate(t_stack *stack, int n)
{
	int 	size;
	int 	half;
	t_stack	*current;
	int		index;

	current = stack;
	size = stack_size(stack);
	half = size / 2;
	while (current)
	{
		if (current->prev->n > n && current->n < n)
			break;
		current = current->next;
		index++;
	}
	if (index <= half)
		return (index);
	else
		return (index - size);
}
