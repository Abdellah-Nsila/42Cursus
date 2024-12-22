#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);
	display_stacks(a, NULL, "After", "Create");
	
}
