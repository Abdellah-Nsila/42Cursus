#include "push_swap.h"
#include "./Libft/libft.h"

void	ft_print_node(t_node *node)
{
	printf("                       Node Members                       \n");
	printf("n:    %d\n", node->n);
	printf("prev: %p\n", node->prev);
	printf("next: %p\n", node->next);
}

void	ft_print_lst(t_node *lst)
{
	t_node	*current;

	if (!lst)
	{
		printf("List is empty !\n");
		return ;
	}
	current = lst;
	do {
		 ft_print_node(current);
		current = current->next;
	} while (current != lst);
}

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
	return (node);
}

void	ft_lst_add_front(t_node **lst, t_node *new)
{
	t_node	*last;

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

t_node	*ft_lst_pop(t_node **lst)
{
	t_node	*popped_node;
	t_node	*last;

	popped_node = *lst;
	if ((*lst)->next == *lst)
	{
		*lst = NULL;
		return (popped_node);
	}
	last = ft_lst_last(*lst);
	(*lst) = (*lst)->next;
	last->next = *lst;
	(*lst)->prev = last;
	popped_node->next = popped_node;
	popped_node->prev = popped_node;
	return (popped_node);
}


void	ft_lst_rotate(t_node **lst)
{
	*lst = (*lst)->next;
}

void	ft_lst_reverse_rotate(t_node **lst)
{
	t_node	*last;

	last = ft_lst_last(*lst);
	*lst = last;
}

void	ft_swap_node_content(t_node **lst)
{
	int	temp;

	temp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = temp;
}

void	ft_swap_real_node(t_node **lst)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst)
		return ;
	first = *lst;
	second = first->next;
	if (second->next == first)
	{
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
		*lst = second;
		return;
	}
	first->next = second->next;
	first->prev = second;
	second->next->prev = first;
	second->next = first;
	second->prev = ft_lst_last(*lst);
	second->prev->next = second;
	*lst = second;
}


