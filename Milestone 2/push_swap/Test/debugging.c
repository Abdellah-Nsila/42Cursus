#include "push_swap.h"

void	print_node(t_stack *node)
{
	ft_printf("|                     Node Members                     |\n");
	ft_printf("| n:    %d                                              |\n", node->n);
	// ft_printf("| prev: %p                                 |\n", node->prev);
	// ft_printf("| next: %p                                 |\n", node->next);
	ft_printf("|______________________________________________________|\n");

}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		ft_printf("|                   List is empty !                    |\n");
		ft_printf("|______________________________________________________|\n");
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
	ft_printf("\n======================== %s %s ========================\n", state, action);
	ft_printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	ft_printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);
}

// t_stack	*generate_stack(char **arr, int size)
// {
// 	t_stack	*head;
// 	t_stack	*new_node;
// 	head = NULL;
// 	while (size--)
// 	{
// 		new_node = new(ft_atoi(arr[size]));
// 		if (!new_node)
// 			return (NULL);
// 		push(&head, new_node);
// 	}
// 	return (head);
// }

t_stack	*generate_stack_test()
{
	t_stack	*head;

	head = NULL;
	for (int i = 1; i < 10; i++)
		push(&head, new(i));
	return (head);
}

void	print_chipset(t_chipset chipset)
{
	ft_printf("\nCost of %d at index %d:\n    %d operation,   %d a_rotation,   %d b_rotation\n"
	, chipset.n, chipset.index, chipset.cost, chipset.a_rotate, chipset.b_rotate);
}
