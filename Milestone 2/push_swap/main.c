#include "push_swap.h"

void	display_stacks(t_node *a, t_node *b, char *state, char *action)
{
	printf("\n======================== %s %s ========================\n", state, action);
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);
}

t_node	*create_stack()
{
	t_node	*head;

	head = NULL;
	for (int i = 10; i < 50; i+=10)
		push(&head, new(i));
	return (head);
}

// //! Test ( Create, Display )
int main()
{
	t_node	*head;

	head = create_stack();
	display_stacks(head, NULL, "After", "Create");
}

// //! Test ( Push, Pop ) in 2 Stack a, b
// int	main()
// {
// 	t_node	*a;
// 	t_node	*b;

// 	a = create_stack();
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
// 	t_node	*a;

// 	a = create_stack();
// 	display_stacks(a, NULL, "Before", "Rotate");

// 	ra_rb_rra_rrb(&a, 'r');
// 	ra_rb_rra_rrb(&a, 'R');
// 	ra_rb_rra_rrb(&a, 'r');

// 	display_stacks(a, NULL, "After", "Rotate");
// }

// //! Test ( Create new node, Push new node in front, Swap 2 first nodes )
// int	main()
// {
// 	t_node	*a;

// 	a = create_stack();
// 	display_stacks(a, NULL, "Before", "Swap");

// 	sa_sb(&a);
// 	display_stacks(a, NULL, "After", "Swap");
// }
