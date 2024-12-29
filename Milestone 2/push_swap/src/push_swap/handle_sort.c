#include "../../includes/push_swap.h"

void	ft_golden_nums(t_stack **a, t_stack **b)
{
	while (!ft_check_is_sorted(*a) && stack_size(*a) > 3)
	{
		ft_execute_command(a, b, PB, 1);
	}
}

void	ft_primary_sort(t_stack **a, t_stack **b)
{
	t_chipset	perfect_chipset;

	ft_execute_command(a, b, PB, 1);
	ft_execute_command(a, b, PB, 1);

	while (stack_size(*a) > 25)
	{
		perfect_chipset = ft_get_perfect_chipset(*a, *b);
		ft_run_perfect_command(a, b, perfect_chipset);
	}
	ft_golden_nums(a, b);
	ft_sort_three(a);
	ft_push_back(a, b);
}

void	ft_sort_stack(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (ft_putstr_fd("Error\n", 2));
	if (ft_check_is_sorted(a))
	{
		ft_clear(&a);
		exit(0);
	}
	size_a = stack_size(a);
	if (size_a == 2)
		ft_sort_two(&a);
	else if (size_a == 3)
		ft_sort_three(&a);
	else if (size_a == 4)
		ft_sort_four(&a, &b);
	else
		ft_primary_sort(&a, &b);
	ft_clear(&a);
	ft_clear(&b);
	exit(0);
}
