#include "../../includes/push_swap.h"

int	ft_check_is_sorted(t_stack *stack){
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->n > current->next->n)
			return (0);
		current = current->next;
		if (current->next->next == stack)
			break;
	}
	return (1);
}

void	ft_sort_three(t_stack **a)
{
	while ((*a)->n > (*a)->next->n || (*a)->next->n > (*a)->next->next->n)
	{
		if ((*a)->n > (*a)->next->n)
			ft_execute_command(a, NULL, SA, 1);
		if ((*a)->n < (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
			break;
		if ((*a)->next->n > (*a)->next->next->n)
			ft_execute_command(a, NULL, RRA, 1);
	}
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	while (stack_size(*b))
	{
		if ((*b)->n < ft_find_min(*a) || (*b)->n > ft_find_max(*a))
		{
			int min_index = ft_find_index(*a, ft_find_min(*a));
			ft_run_perfect_rotation(a, ft_calculate_rotate(*a, min_index), STACK_A);
		}
		else
		{
			while ((*a)->prev->n > (*b)->n)
				ft_execute_command(a, NULL, RRA, 1);
		}
		ft_execute_command(a, b, PA, 1);
	}
	int min_index = ft_find_index(*a, ft_find_min(*a));
	ft_run_perfect_rotation(a, ft_calculate_rotate(*a, min_index), STACK_A);
}

void	ft_primary_sort(t_stack **a, t_stack **b)
{
	t_command	perfect_chipset;

	ft_execute_command(b, a, PB, 1);
	ft_execute_command(b, a, PB, 1);

	// I try to get the chipset of each number and return the perfect chipset
	while (stack_size(*a) > 3)
	{
		perfect_chipset = ft_get_perfect_chipset(*a, *b);
		ft_run_perfect_command(a, b, perfect_chipset);
	}

	// Sort last three element in stack A
	ft_sort_three(a);

	// Pushing back to STACK_A (assending order)
	ft_push_back(a, b);
}
