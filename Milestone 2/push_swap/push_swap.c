#include "push_swap.h"

int	ft_isnumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_check_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
		if (!ft_isnumber(av[i]))
			return (0);
	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
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
		return (ft_check_numbers(ac, av));
	}
	else if (ac == 2)
	{
		
		arr = ft_split(av[1], ' ');
		return (ft_check_numbers(ft_wordscount(av[1], ' '), arr));
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