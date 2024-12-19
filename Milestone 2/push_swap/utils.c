#include "push_swap.h"

void	ft_print_node(t_node *node)
{
	printf("                       Node Members                       \n");
	printf("n:    %d\n", node->n);
	printf("prev: %p\n", node->prev);
	printf("next: %p\n", node->next);
}

void	ft_print_stack(t_node *stack)
{
	t_node	*current;

	if (!stack)
	{
		printf("List is empty !\n");
		return ;
	}
	current = stack;
	do {
		 ft_print_node(current);
		current = current->next;
	} while (current != stack);
}

t_node	*ft_stack_last(t_node *stack)
{
	t_node	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current->next != stack)
		current = current->next;
	return (current);
}

t_node	*ft_stack_new(int n)
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

void	ft_stack_add_front(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!(*stack)) {
		*stack = new;
		return;
	}
	last = ft_stack_last(*stack);
	new->next = *stack;
	new->prev = last;
	(*stack)->prev = new;
	last->next = new;
	*stack = new;
}

t_node	*ft_stack_pop(t_node **stack)
{
	t_node	*popped_node;
	t_node	*last;

	popped_node = *stack;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return (popped_node);
	}
	last = ft_stack_last(*stack);
	(*stack) = (*stack)->next;
	last->next = *stack;
	(*stack)->prev = last;
	popped_node->next = popped_node;
	popped_node->prev = popped_node;
	return (popped_node);
}


void	ft_stack_rotate(t_node **stack)
{
	*stack = (*stack)->next;
}

void	ft_stack_reverse_rotate(t_node **stack)
{
	t_node	*last;

	last = ft_stack_last(*stack);
	*stack = last;
}

void	ft_swap_node_content(t_node **stack)
{
	int	temp;

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void	ft_swap_real_node(t_node **stack)
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
	second->prev = ft_stack_last(*stack);
	second->prev->next = second;
	*stack = second;
}


