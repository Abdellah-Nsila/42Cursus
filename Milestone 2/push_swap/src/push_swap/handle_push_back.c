#include "../../includes/push_swap.h"

static int	ft_find_pos(t_stack *stack, int n, int f, int i)
{
	int	a;
	int	b;
	int	edge;
	t_stack	*current;

	current = stack;
	edge = 0;
	while (current->next != stack && ++i)
	{
		a = current->n;
		b = current->next->n;
		if (a > b)
		{
			edge = i;
			current = current->next;
			continue ;
		}
		if (n > a && n < b)
			return (i);
		current = current->next;
	}
	if ((b < f && n > b && n < f) || (f < b && n < b && n > f))
		return (0);
	return (edge);
}

static int	ft_calculate_a_rotate(t_stack *stack, int n)
{
	int first = stack->n;
	int index = ft_find_pos(stack, n, first, 0);
	return (ft_calculate_rotate(stack, index));
}

static void	ft_return_num_to_stack_a(t_stack **a, t_stack **b)
{
	int		num;
	int		x_rotate;
	int		b_pos;

	num = (*b)->n;
	b_pos = ft_get_pos_of(*a, num);
	x_rotate = ft_calculate_rotate(*a, b_pos) ;
	ft_run_perfect_rotation(a, x_rotate, STACK_A);
	ft_execute_command(a, b, PA, 1);
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	int min_index;

	while (*b)
		ft_return_num_to_stack_a(a, b);
	min_index = ft_find_index(*a, ft_find_min(*a));
	ft_run_perfect_rotation(a, ft_calculate_rotate(*a, min_index), STACK_A);
}
