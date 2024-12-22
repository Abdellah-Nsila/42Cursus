#include "push_swap.h"

void	print_node(t_stack *node)
{
	printf("|                     Node Members                     |\n");
	printf("| n:    %d                                             |\n", node->n);
	printf("| prev: %p                                 |\n", node->prev);
	printf("| next: %p                                 |\n", node->next);
	printf("|______________________________________________________|\n");

}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

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

void	display_stacks(t_stack *a, t_stack *b, char *state, char *action)
{
	printf("\n======================== %s %s ========================\n", state, action);
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);
}

t_stack	*generate_stack(char **arr, int size)
{
	int		i;
	t_stack	*head;
	t_stack	*new_node;

	i= 0;
	head = NULL;
	while (size--)
	{
		new_node = new(ft_atoi(arr[size]));
		if (!new_node)
			return (NULL);
		push(&head, new_node);
	}
	return (head);
}

t_stack	*generate_stack_test()
{
	t_stack	*head;

	head = NULL;
	for (int i = 10; i < 50; i+=10)
		push(&head, new(i));
	return (head);
}
