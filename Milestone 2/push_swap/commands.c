#include "push_swap.h"

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}

void	put(t_node **from_stack, t_node **to_stack)
{
	push(to_stack, pop(from_stack));
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
