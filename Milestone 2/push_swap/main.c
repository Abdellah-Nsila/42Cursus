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

	node1 = new(10);
	node2 = new(20);
	node3 = new(30);
	node4 = new(40);

	push(&a, node1);
	push(&a, node2);
	push(&a, node3);
	push(&a, node4);

	printf("\n======================== Before ========================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);

	// Pop from stack a, and Push to b
	put(&a, &b);
	put(&a, &b);
	put(&a, &b);
	put(&a, &b);

	printf("\n\n\n========================= After =========================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);

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
// 	node1 = new(10);
// 	node2 = new(20);
// 	node3 = new(30);
// 	node4 = new(40);

// 	push(&head, node1);
// 	push(&head, node2);
// 	push(&head, node3);
// 	push(&head, node4);
// 	printf("\n======================= Before Rotate =======================\n");
// 	print_stack(head);

// 	rotate(&head);
// 	reverse_rotate(&head);
// 	printf("\n\n======================= After Rotate =======================\n");
// 	print_stack(head);
// }

//! Test ( Create new node, Push new node in front, Swap 2 first nodes )
// int	main()
// {
// 	t_node	*head;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;

// 	head = NULL;
// 	node1 = new(10);
// 	node2 = new(20);
// 	node3 = new(30);

// 	push(&head, node1);
// 	push(&head, node2);
// 	push(&head, node3);
// 	printf("\n======================= Before Swap =======================\n");
// 	print_stack(head);

// 	swap(&head);
// 	printf("\n\n======================= After Swap =======================\n");
// 	print_stack(head);
// }
