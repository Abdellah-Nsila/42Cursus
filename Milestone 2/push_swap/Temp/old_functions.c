#include "push_swap.h"

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_stack;

	last_stack = last(*stack);
	*stack = last_stack;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	ft_swap_node_content(t_stack **stack)
{
	int	temp;
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/* rotate_to_index
 * Rotate a specifique node to the top of the stack based on his index position.
 * Check the fast command (rx, rrx) based on node position (before or after the half).
 * @param stack: Target stack
 * @param index: Index of target node
 * @param target: Flag to the target stack `{0: stack a, 1: stack b}`
 **/
void rotate_to_index(t_stack **stack, int index, int target)
{
	int i;
	int size;
	int half;

	i = 0;
	size = stack_size(*stack);
	half = size / 2;
	if (index <= half)
		while (i++ < index)
			ft_execute_command(stack, NULL, RA + target);
	else
		while (i++ < (size - index))
			ft_execute_command(stack, NULL, RRA + target);
}