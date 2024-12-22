#include "push_swap.h"

/* ft_validate_arg
 * Check the type of element in array 
 * Must containe only numbers, Non duplicated, INT MIN - INT MAX included .
 * @param arr: Array of strings (numbers before converted to numbers)
 * @param size: Size of the array (number of elements)
 * @return: A bool flag (TRUE - FALSE)
 **/
int	ft_validate_arg(char **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (!ft_isnumber(arr[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* ft_init_stack
 * Validate arguments, two cases:
 * Multiple arguments, One string argument must be splited,
 * Also Generate stack a
 * @param ac: Number of arguments
 * @param av: List of arguments
 * @return: stack a
 **/
t_stack	*ft_init_stack(int ac, char **av)
{
	int		i;
	char	**arr;
	int		size;

	i = 0;
	if (ac > 2)
	{
		if (ft_validate_arg(av+1, ac - 1))
			return (generate_stack(av+1, ac - 1));
	}
	else if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		size = ft_wordscount(av[1], ' ');
		if (arr == NULL || size == 0)
			return (NULL);
		if (ft_validate_arg(arr, size))
			return (generate_stack(arr, size));
	}
	return (NULL);
}
