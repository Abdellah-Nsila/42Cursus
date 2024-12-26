#include "../includes/push_swap.h"

t_stack	*generate_stack(char **arr, int size)
{
	t_stack	*head;
	t_stack	*new_node;

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

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);
	if (ft_check_is_sorted(a))
		return (1);
	ft_primary_sort(&a, &b);
}
