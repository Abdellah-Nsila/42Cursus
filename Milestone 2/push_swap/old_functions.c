#include "push_swap.h"

void	rotate(t_node **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	last_node = last(*stack);
	*stack = last_node;
}

void	ft_swap_node_content(t_node **stack)
{
	int	temp;
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}