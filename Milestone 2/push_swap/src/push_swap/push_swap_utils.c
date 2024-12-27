#include "../../includes/push_swap.h"

t_stack	*last(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != stack)
		current = current->next;
	return (current);
}

t_stack	*new(int n)
{
	t_stack	*node;

	node = (t_stack*) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = node;
	node->next = node;
	return (node);
}

void	push(t_stack **stack, t_stack *new)
{
	t_stack	*last_stack;

	if (!(*stack)) {
		*stack = new;
		return;
	}
	last_stack = last(*stack);
	new->next = *stack;
	new->prev = last_stack;
	(*stack)->prev = new;
	last_stack->next = new;
	*stack = new;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*popped_stack;
	t_stack	*last_stack;

	popped_stack = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return (popped_stack);
	}
	last_stack = last(*stack);
	(*stack) = (*stack)->next;
	last_stack->next = *stack;
	(*stack)->prev = last_stack;
	popped_stack->next = popped_stack;
	popped_stack->prev = popped_stack;
	return (popped_stack);
}

int	stack_size(t_stack *stack)
{
	t_stack *current;
	int     size;

	current = stack;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
		if (current == stack)
			break;
	}
	return (size);
}
