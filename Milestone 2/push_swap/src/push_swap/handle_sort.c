#include "../../includes/push_swap.h"

int	ft_check_is_sorted(t_stack *stack){
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->next == stack)
			break;
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_primary_sort(t_stack **a, t_stack **b)
{
	t_chipset	perfect_chipset;

	ft_execute_command(b, a, PB, 1);
	ft_execute_command(b, a, PB, 1);

	while (stack_size(*a) > 3)
	{
		perfect_chipset = ft_get_perfect_chipset(*a, *b);
		ft_run_perfect_command(a, b, perfect_chipset);
	}
	ft_sort_three(a);
	ft_push_back(a, b);
}
