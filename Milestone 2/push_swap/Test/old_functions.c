#include "push_swap.h"

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_stack;

	last_stack = last(*stack);
	*stack = last_stack;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	ft_swap_node_content(t_stack **stack)
{
	int	temp;
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

void rotate_to_index(t_stack **stack, int index, int target)
{
	int i;
	int size;
	int half;

	i = 0;
	size = stack_size(*stack);
	half = size / 2;
	if (index <= half)
		while (i++ < index)
			ft_execute_command(stack, NULL, RA + target);
	else
		while (i++ < (size - index))
			ft_execute_command(stack, NULL, RRA + target);
}

int	ft_calculate_top_max(t_stack *stack, int max)
{
	int	index;

	index = ft_find_index(stack, max);
	return (ft_calculate_best_rotate(stack, index));
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
void	ft_clear_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

t_stack	*ft_handle_string(int ac, char **av)
{
	t_stack	*stack;
	char	**arr;
	int		size;

	arr = ft_split(av[1], ' ');
	size = ft_wordscount(av[1], ' ');
	if (arr == NULL || size == 0)
		return (ft_clear_arr(arr), NULL);
	if (ft_validate_arg(arr, size))
	{
		stack = generate_stack(arr, size);
		ft_clear_arr(arr);
		return (stack);
	}
	ft_clear_arr(arr);
	return (NULL);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	if (ac > 2 && ft_validate_arg(av+1, ac - 1))
		return (generate_stack(av+1, ac - 1));
	else if (ac == 2)
		return (ft_handle_string(ac, av));
	return (NULL);
}

int	ft_validate_arg(char **arr, int size)
{
	int		i;
	int		j;
	long	num;

	if (size <= 0)
		return (1);
	i = 0;
	while (i < size) {
		if (!ft_isnumber(arr[i]))
			return (0);
		num = ft_atol(arr[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	i = 0;
	while (i < size) {
		j = i + 1;
		while (j < size) {
			if (ft_atol(arr[i]) == ft_atol(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_execute_single_stack(t_stack **s, int t, int f, const char *c)
{
	if (t == SA || t == SB)
		sa_sb(s);
	else if (t == RA || t == RB)
		ra_rb_rra_rrb(s, t);
	else if (t == RRA || t == RRB)
		ra_rb_rra_rrb(s, t);
	if (f)
		ft_printf("%s\n", c);
}

void	ft_execute_dual_stack(t_stack **a, t_stack **b, int t, int f, const char *c)
{
	if (t == PA)
		pa_pb(a, b);
	else if (t == PB)
		pa_pb(b, a);
	else if (t == RR || t == RRR)
		rr_rrr(a, b, t);
	if (f)
		ft_printf("%s\n", c);
}

void	ft_execute_command(t_stack **a, t_stack **b, int type, int flag)
{
	const char *commands[10];

	commands[SA] = "sa";
	commands[SB] = "sb";
	commands[PA] = "pa";
	commands[PB] = "pb";
	commands[RA] = "ra";
	commands[RB] = "rb";
	commands[RRA] = "rra";
	commands[RRB] = "rrb";
	commands[RR] = "rr";
	commands[RRR] = "rrr";

	if (type == SA || type == SB || type == RA || type == RB || type == RRA || type == RRB)
		ft_execute_single_stack((type == SA || type == RA || type == RRA) ? a : b, type, flag, commands[type]);
	else if (type == PA || type == PB || type == RR || type == RRR)
		ft_execute_dual_stack(a, b, type, flag, commands[type]);
}
