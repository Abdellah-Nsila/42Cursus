#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*head;

	head = ft_validate_arg(ac, av);
	display_stacks(head, NULL, "After", "Create");
	// printf("isValide: %d\n", ft_validate_arg(ac, av));e
	
}
