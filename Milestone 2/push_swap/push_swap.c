#include "push_swap.h"

int	ft_isnumber(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_numbers(char **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	//* Print the arr based in size gived in argument
	// while (i < size)
	// {
	// 	printf("i: %d  n: %s\n",i, arr[i]);
	// 	i++;
	// }
	// printf("\n");
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

int	ft_validate_arg(int ac, char **av)
{
	int	i;
	char	**arr;

	i = 0;
	if (ac > 2)
	{
		// if (ft_check_numbers(ac, av) == 0)
		// 	return (0);
		return (ft_check_numbers(av+1, ac - 1));
	}
	else if (ac == 2)
	{
		
		arr = ft_split(av[1], ' ');
		return (ft_check_numbers(arr, ft_wordscount(av[1], ' ')));
		// printf("count: %d\n", ft_wordscount(av[1], ' '));
		// while (arr[i])
		// {
		// 	printf("%s ", arr[i]);
		// 	i++;
		// }
		// printf("\n");
	}
	else
		return (0);
}

int	main(int ac, char **av)
{
	// 1 - Multiple argument: 
	//		Type of each arg is number
	//		Non duplicate
	//		INT MIN - INT MAX included 
	// 2 - One argument	:
	//		Split them by space
	//		Type of each arg is number
	//		Non duplicate
	//		INT MIN - INT MAX included 

	printf("isValide: %d\n", ft_validate_arg(ac, av));
	
	// printf("n: %d\n", ft_atoi(av[1]));
}