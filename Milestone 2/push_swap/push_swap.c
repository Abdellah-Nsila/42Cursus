#include "push_swap.h"

// Example:

//? 2 1 3 6 5 8  => pb pb rrb pb sa pa pa pa => 1 2 3 5 6 8 : 8 instructions 💪
	//* pa_pb(&a, &b);
	//* pa_pb(&a, &b);

	//* ra_rb_rra_rrb(&b, 'R');
	//* pa_pb(&a, &b);

	//* sa_sb(&a);

	//* pa_pb(&b, &a);
	//* pa_pb(&b, &a);
	//* pa_pb(&b, &a);


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);
	display_stacks(a, b, "After", "Create");
	
	pa_pb(&a, &b);
	pa_pb(&a, &b);
	ra_rb_rra_rrb(&b, 'R');
	pa_pb(&a, &b);
	sa_sb(&a);
	pa_pb(&b, &a);
	pa_pb(&b, &a);
	pa_pb(&b, &a);
	display_stacks(a, b, "After", "Create");
}
