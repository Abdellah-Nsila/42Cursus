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

void rotate_to_index(t_stack **stack, int index)
{
	int size;
	int half;
	int i;

	size = stack_size(*stack);
	half = size / 2;
	i = 0;
	if (index <= half)
		while (i++ < index)
			ra_rb_rra_rrb(stack, 'r');
	else
		while (i++ < (size - index))
			ra_rb_rra_rrb(stack, 'R');

}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);
	display_stacks(a, b, "After", "Create");
	rotate_to_index(&a, 3);
	display_stacks(a, b, "After", "Create");
	//TODO Working in finding the perfect position 
	printf("pos: %d", ft_find_position(b, 6));


	// pa_pb(&a, &b);
	// pa_pb(&a, &b);

	// display_stacks(a, b, "After", "Create");

// 	printf("Max: %d\n", ft_find_max(a));
// 	printf("Min: %d\n", ft_find_min(a));
}
