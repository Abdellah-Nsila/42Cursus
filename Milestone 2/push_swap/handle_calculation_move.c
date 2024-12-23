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
	int size;
	int half;

	size = stack_size(stack);
	half = size / 2;
	// if (index <= half)
	// 	return (index);
	// return (index - size);
}
