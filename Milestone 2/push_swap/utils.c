#include "push_swap.h"

void	print_node(t_node *node)
{
	printf("|                     Node Members                     |\n");
	printf("| n:    %d                                             |\n", node->n);
	printf("| prev: %p                                 |\n", node->prev);
	printf("| next: %p                                 |\n", node->next);
	printf("|______________________________________________________|\n");

}

void	print_stack(t_node *stack)
{
	t_node	*current;

	if (!stack)
	{
		printf("|                   List is empty !                    |\n");
		printf("|______________________________________________________|\n");
		return ;
	}
	current = stack;
	do {
		 print_node(current);
		current = current->next;
	} while (current != stack);
}

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

void	swap(t_node **stack)
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

// void	ft_swap_node_content(t_node **stack)
// {
// 	int	temp;
// 	temp = (*stack)->n;
// 	(*stack)->n = (*stack)->next->n;
// 	(*stack)->next->n = temp;
// }
