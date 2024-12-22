#include "push_swap.h"

/* ft_check_numbers
 * Check the type of element in array 
 * Must containe only numbers, Non duplicated, INT MIN - INT MAX included .
 * @param arr: Array of strings (numbers before converted to numbers)
 * @param size: Size of the array (number of elements)
 * @return: A bool flag (TRUE - FALSE)
 **/
int	ft_check_numbers(char **arr, int size)
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

/* ft_validate_arg
 * Validate arguments, two cases
 * Multiple arguments, One string argument must be splited.
 * @param ac: Number of arguments
 * @param size: List of arguments
 * @return: A bool flag (TRUE - FALSE)
 **/
int	ft_validate_arg(int ac, char **av)
{
	int		i;
	char	**arr;
	int		size;

	i = 0;
	if (ac > 2)
		return (ft_check_numbers(av+1, ac - 1));
	else if (ac == 2)
	{
		arr = ft_split(av[1], ' ');
		size = ft_wordscount(av[1], ' ');
		if (arr == NULL || size == 0)
			return (0);
		return (ft_check_numbers(arr, size));
	}
	else
		return (0);
}
