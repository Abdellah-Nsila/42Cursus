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


// void	ft_execute_command(t_stack **primary, t_stack **secondary, int command_type, int target_stack)
void	ft_execute_command(t_stack **primary, t_stack **secondary, int type)
{
	const char *commands[10];
	// int	type;

	commands[SA] = "sa";
	commands[SB] = "sb";
	commands[PA] = "pa";
	commands[PB] = "pb";
	commands[RA] = "ra";
	commands[RB] = "rb";
	commands[RRA] = "rra";
	commands[RRB] = "rrb";
	commands[RR] = "rr";
	commands[RRR] = "rrr";

	// type = command_type + target_stack;
	if (type == SA || type == SB)
		sa_sb(primary);
	if (type == RA || type == RB || type == RRA || type == RRB)
		ra_rb_rra_rrb(primary, type);
	printf("%s\n", commands[type]);
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
			ft_execute_command(stack, NULL, 4 + target);
	else
		while (i++ < (size - index))
			ft_execute_command(stack, NULL, 6 + target);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);

	pa_pb(&a, &b);
	pa_pb(&a, &b);
	// rotate_to_index(&a, 3);
	display_stacks(a, b, "After", "Create");
	//TODO Working in finding the perfect position 
	rotate_to_index(&a, 2, 0);
	ft_execute_command(&a, NULL, SA);
	ft_execute_command(&b, NULL, SB);
	display_stacks(a, b, "After", "Create");
}
