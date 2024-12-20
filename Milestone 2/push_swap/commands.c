#include "push_swap.h"

void	swap(t_node **stack)
{
	ft_swap_real_node(stack);
}

void	ss(t_node **a, t_node **b)
{
	ft_swap_real_node(a);
	ft_swap_real_node(b);
}

void	push(t_node **from_stack, t_node **to_stack)
{
	ft_stack_push(to_stack, ft_stack_pop(from_stack));
}

void	rotate(t_node **stack)
{
	ft_stack_rotate(stack);
}

void	rr(t_node **a, t_node **b)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
}

void	reverse_rotate(t_node **stack)
{
	ft_stack_reverse_rotate(stack);
}

void	rrr(t_node **a, t_node **b)
{
	ft_stack_reverse_rotate(a);
	ft_stack_reverse_rotate(b);
}
