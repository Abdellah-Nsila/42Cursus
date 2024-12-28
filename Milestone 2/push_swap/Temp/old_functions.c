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

/* rotate_to_index
 * Rotate a specifique node to the top of the stack based on his index position.
 * Check the fast command (rx, rrx) based on node position (before or after the half).
 * @param stack: Target stack
 * @param index: Index of target node
 * @param target: Flag to the target stack `{0: stack a, 1: stack b}`
 **/
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
// void	ft_clear_arr(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	arr = NULL;
// }

// t_stack	*ft_handle_string(int ac, char **av)
// {
// 	t_stack	*stack;
// 	char	**arr;
// 	int		size;

// 	arr = ft_split(av[1], ' ');
// 	size = ft_wordscount(av[1], ' ');
// 	if (arr == NULL || size == 0)
// 		return (ft_clear_arr(arr), NULL);
// 	if (ft_validate_arg(arr, size))
// 	{
// 		stack = generate_stack(arr, size);
// 		ft_clear_arr(arr);
// 		return (stack);
// 	}
// 	ft_clear_arr(arr);
// 	return (NULL);
// }

// t_stack	*ft_init_stack(int ac, char **av)
// {
// 	if (ac > 2 && ft_validate_arg(av+1, ac - 1))
// 		return (generate_stack(av+1, ac - 1));
// 	else if (ac == 2)
// 		return (ft_handle_string(ac, av));
// 	return (NULL);
// }







