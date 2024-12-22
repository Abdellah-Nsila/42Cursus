#include "push_swap.h"

void	sa_sb(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
		*stack = second;
		return;
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = last(*stack);
	second->prev->next = second;
	*stack = second;
}

void	ss(t_node **a, t_node **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	pa_pb(t_node **from_stack, t_node **to_stack)
{
	push(to_stack, pop(from_stack));
}

void	ra_rb_rra_rrb(t_node **stack, char type)
{
	if ((*stack)->next == *stack)
		return ;
	if (type == 'r')
		*stack = (*stack)->next;
	else if (type == 'R')
		*stack = last(*stack);
}

void	rr_rrr(t_node **a, t_node **b, char type)
{
	ra_rb_rra_rrb(a, type);
	ra_rb_rra_rrb(b, type);
}
