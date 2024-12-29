#include "../../includes/push_swap.h"

void	ft_clear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		if (temp == *stack)
			break;
		current = temp;
	}
	*stack = NULL;
}

void	ft_clear_arr(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int ft_validate_arg(char **arr, int size)
{
	int i, j;
	long num;

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

t_stack	*ft_handle_string(int ac, char **av)
{
	t_stack	*stack;
	char	**arr;
	int		size;

	arr = ft_split(av[1], ' ');
	if (!arr)
		return (NULL);
	size = ft_wordscount(av[1], ' ');
	if (size == 0 || !ft_validate_arg(arr, size))
		return (ft_clear_arr(arr), NULL);
	stack = generate_stack(arr, size);
	ft_clear_arr(arr);
	return (stack);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	if (ac > 2)
	{
		if (ft_validate_arg(av + 1, ac - 1))
			return (generate_stack(av + 1, ac - 1));
		return (NULL);
	}
	else if (ac == 2)
		return (ft_handle_string(ac, av));
	return (NULL);
}
