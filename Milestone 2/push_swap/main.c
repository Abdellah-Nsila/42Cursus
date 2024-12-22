#include "push_swap.h"

//! Test ( Genarate, Display )
int main()
{
	t_stack	*head;

	head = generate_stack_test();
	display_stacks(head, NULL, "After", "Create");
}

// //! Test ( Push, Pop ) in 2 Stack a, b
// int	main()
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = generate_stack_test();
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

// 	a = generate_stack_test();
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

// 	a = generate_stack_test();
// 	display_stacks(a, NULL, "Before", "Swap");

// 	sa_sb(&a);
// 	display_stacks(a, NULL, "After", "Swap");
// }
