#include "../../includes/push_swap.h"

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
	int			size_a;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (ft_printf("Error\n"), 0);
	if (ft_check_is_sorted(a))
		return (1);
	size_a = stack_size(a);
	if (size_a == 2)
		ft_sort_two(&a);
	else if (size_a == 3)
		ft_sort_three(&a);
	else if (size_a == 4)
		ft_sort_four(&a, &b);
	else
		ft_primary_sort(&a, &b);
}
