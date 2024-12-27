#include "../../includes/push_swap.h"

void	ft_sort_two(t_stack **a)
{
	if ((*a)->n > (*a)->next->n)
		ft_execute_command(a, NULL, SA, 1);
}

void	ft_sort_three(t_stack **a)
{
	// 3 1 2 case
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
		&& (*a)->n > (*a)->next->next->n)
		ft_execute_command(a, NULL, RA, 1);
	else
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
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	ft_execute_command(b, a, PB, 1);
	ft_sort_three(a);
	ft_push_back(a, b);
}
