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

t_stack	*genarate_stack_test()
{
	t_stack	*head;

	head = NULL;
	for (int i = 10; i < 50; i+=10)
		push(&head, new(i));
	return (head);
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

// //! Test ( Genarate, Display )
// int main()
// {
// 	t_stack	*head;

// 	head = genarate_stack_test();
// 	display_stacks(head, NULL, "After", "Create");
// }

// //! Test ( Push, Pop ) in 2 Stack a, b
// int	main()
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = genarate_stack_test();
// 	b = NULL;
// 	display_stacks(a, b, "Before", "Put");

// 	// Pop from stack a, and Push to b
// 	pa_pb(&a, &b);
// 	pa_pb(&a, &b);
// 	pa_pb(&a, &b);
// 	pa_pb(&a, &b);

// 	display_stacks(a, b, "Before", "Put");
// }


// //! Test ( Rotate list, Reverse Rotate list )
// int	main()
// {
// 	t_stack	*a;

// 	a = genarate_stack_test();
// 	display_stacks(a, NULL, "Before", "Rotate");

// 	ra_rb_rra_rrb(&a, 'r');
// 	ra_rb_rra_rrb(&a, 'R');
// 	ra_rb_rra_rrb(&a, 'r');

// 	display_stacks(a, NULL, "After", "Rotate");
// }

// //! Test ( Create new node, Push new node in front, Swap 2 first nodes )
// int	main()
// {
// 	t_stack	*a;

// 	a = genarate_stack_test();
// 	display_stacks(a, NULL, "Before", "Swap");

// 	sa_sb(&a);
// 	display_stacks(a, NULL, "After", "Swap");
// }
