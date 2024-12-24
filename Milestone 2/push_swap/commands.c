#include "push_swap.h"

void	sa_sb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

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

void	ss(t_stack **a, t_stack **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	pa_pb(t_stack **to_stack, t_stack **from_stack)
{
	push(to_stack, pop(from_stack));
}

//TODO Destermine wich command is executed
void	ra_rb_rra_rrb(t_stack **stack, int type)
{

	if ((*stack)->next == *stack)
		return ;
	if (type == RA || type == RB)
		*stack = (*stack)->next;
	else if (type == RRA || type == RRB)
		*stack = last(*stack);
}

void	rr_rrr(t_stack **a, t_stack **b, int type)
{
	if (type == RR)
		type = RA;
	else if (type == RRR)
		type = RRA;
	ra_rb_rra_rrb(a, type);
	ra_rb_rra_rrb(b, type);
}
