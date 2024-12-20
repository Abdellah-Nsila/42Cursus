#include "push_swap.h"

//! Test ( Push, Pop ) in 2 Stack a, b
int	main()
{
	t_node	*a;
	t_node	*b;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*popped_node;

	a = NULL;
	b = NULL;

	node1 = ft_stack_new(10);
	node2 = ft_stack_new(20);
	node3 = ft_stack_new(30);
	node4 = ft_stack_new(40);

	ft_stack_push(&a, node1);
	ft_stack_push(&a, node2);
	ft_stack_push(&a, node3);
	ft_stack_push(&a, node4);

	printf("\n======================== Before ========================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_stack(b);

	// Pop from stack a, and Push to b
	ft_stack_push(&b, ft_stack_pop(&a));
	ft_stack_push(&b, ft_stack_pop(&a));
	ft_stack_push(&b, ft_stack_pop(&a));
	ft_stack_push(&b, ft_stack_pop(&a));

	printf("\n\n\n========================= After =========================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_stack(b);

	return (0);
}


//! Test ( Rotate list, Reverse Rotate list )
// int	main()
// {
// 	t_node	*head;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;
// 	t_node	*node4;

// 	head = NULL;
// 	node1 = ft_stack_new(10);
// 	node2 = ft_stack_new(20);
// 	node3 = ft_stack_new(30);
// 	node4 = ft_stack_new(40);

// 	ft_stack_push(&head, node1);
// 	ft_stack_push(&head, node2);
// 	ft_stack_push(&head, node3);
// 	ft_stack_push(&head, node4);
// 	printf("\n======================= Before Rotate =======================\n");
// 	ft_print_stack(head);

// 	ft_stack_rotate(&head);
// 	ft_stack_reverse_rotate(&head);
// 	printf("\n\n======================= After Rotate =======================\n");
// 	ft_print_stack(head);
// }

//! Test ( Create new node, Push new node in front, Swap 2 first nodes )
// int	main()
// {
// 	t_node	*head;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;

// 	head = NULL;
// 	node1 = ft_stack_new(10);
// 	node2 = ft_stack_new(20);
// 	node3 = ft_stack_new(30);

// 	ft_stack_push(&head, node1);
// 	ft_stack_push(&head, node2);
// 	ft_stack_push(&head, node3);
// 	printf("\n======================= Before Swap =======================\n");
// 	ft_print_stack(head);

// 	ft_real_swap_node(&head);
// 	printf("\n\n======================= After Swap =======================\n");
// 	ft_print_stack(head);
// }
