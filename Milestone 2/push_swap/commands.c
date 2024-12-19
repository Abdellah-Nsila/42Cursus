#include "push_swap.h"
#include "./Libft/libft.h"

t_node	*ft_lst_last(t_node *lst)
{
	t_node	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != lst)
		current = current->next;
	return (current);
}

t_node	*ft_lst_new(int n)
{
	t_node	*node;

	node = (t_node*) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = node;
	node->next = node;
	// node->prev = ft_strdup("prev");
	// node->next = ft_strdup("next");
	return (node);
}

void	ft_lst_add_front(t_node **lst, t_node *new)
{
	t_node	*last;
	void	*prev;
	void	*next;

	if (!lst || !new)
		return;
	if (!(*lst)) {
		*lst = new;
		return;
	}
	last = ft_lst_last(*lst);
	new->next = *lst;
	new->prev = last;
	(*lst)->prev = new;
	last->next = new;
	*lst = new;
}

void	ft_print_node(t_node *node)
{
	printf("---------------------- Node Members ----------------------\n");
	printf("n:    %d\n", node->n);
	printf("prev: %p\n", node->prev);
	printf("next: %p\n", node->next);
}

void	ft_print_lst(t_node *lst)
{
	t_node	*current;

	current = lst;
	do {
		 ft_print_node(current);
		current = current->next;
	} while (current != lst);
}

int	main()
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	head = NULL;
	node1 = ft_lst_new(10);
	node2 = ft_lst_new(20);
	node3 = ft_lst_new(30);

	ft_lst_add_front(&head, node1);
	ft_lst_add_front(&head, node2);
	ft_lst_add_front(&head, node3);

	ft_print_lst(head);
}
