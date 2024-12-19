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

	node1 = ft_lst_new(10);
	node2 = ft_lst_new(20);
	node3 = ft_lst_new(30);
	node4 = ft_lst_new(40);

	ft_lst_add_front(&a, node1);
	ft_lst_add_front(&a, node2);
	ft_lst_add_front(&a, node3);
	ft_lst_add_front(&a, node4);

	printf("\n======================= Before =======================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_lst(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_lst(b);

	// Pop from stack a, and Push to b
	ft_lst_add_front(&b, ft_lst_pop(&a));
	ft_lst_add_front(&b, ft_lst_pop(&a));
	ft_lst_add_front(&b, ft_lst_pop(&a));
	ft_lst_add_front(&b, ft_lst_pop(&a));

	printf("\n\n\n======================= After =======================\n");
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_lst(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^\n");
	ft_print_lst(b);


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
// 	node1 = ft_lst_new(10);
// 	node2 = ft_lst_new(20);
// 	node3 = ft_lst_new(30);
// 	node4 = ft_lst_new(40);

// 	ft_lst_add_front(&head, node1);
// 	ft_lst_add_front(&head, node2);
// 	ft_lst_add_front(&head, node3);
// 	ft_lst_add_front(&head, node4);
// 	printf("\n======================= Before Rotate =======================\n");
// 	ft_print_lst(head);

// 	ft_lst_rotate(&head);
// 	ft_lst_reverse_rotate(&head);
// 	printf("\n\n======================= After Rotate =======================\n");
// 	ft_print_lst(head);
// }

//! Test ( Create new node, Push new node in front, Swap 2 first nodes )
// int	main()
// {
// 	t_node	*head;
// 	t_node	*node1;
// 	t_node	*node2;
// 	t_node	*node3;

// 	head = NULL;
// 	node1 = ft_lst_new(10);
// 	node2 = ft_lst_new(20);
// 	node3 = ft_lst_new(30);

// 	ft_lst_add_front(&head, node1);
// 	ft_lst_add_front(&head, node2);
// 	ft_lst_add_front(&head, node3);
// 	printf("\n======================= Before Swap =======================\n");
// 	ft_print_lst(head);

// 	ft_real_swap_node(&head);
// 	printf("\n\n======================= After Swap =======================\n");
// 	ft_print_lst(head);
// }
