#include "push_swap.h"

t_node	*last(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != stack)
		current = current->next;
	return (current);
}

t_node	*new(int n)
{
	t_node	*node;

	node = (t_node*) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = node;
	node->next = node;
	return (node);
}

void	push(t_node **stack, t_node *new)
{
	t_node	*last_node;

	if (!(*stack)) {
		*stack = new;
		return;
	}
	last_node = last(*stack);
	new->next = *stack;
	new->prev = last_node;
	(*stack)->prev = new;
	last_node->next = new;
	*stack = new;
}

t_node	*pop(t_node **stack)
{
	t_node	*popped_node;
	t_node	*last_node;

	popped_node = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return (popped_node);
	}
	last_node = last(*stack);
	(*stack) = (*stack)->next;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	popped_node->next = popped_node;
	popped_node->prev = popped_node;
	return (popped_node);
}



