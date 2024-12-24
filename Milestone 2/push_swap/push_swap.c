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

	if (type == SA || type == SB)
		sa_sb(primary);
	else if (type == PA || type == PB)
		pa_pb(primary, secondary);
	else if (type == RA || type == RB || type == RRA || type == RRB)
		ra_rb_rra_rrb(primary, type);
	else if (type == RR || type == RRR)
		rr_rrr(primary, secondary, type);
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
			ft_execute_command(stack, NULL, RA + target);
	else
		while (i++ < (size - index))
			ft_execute_command(stack, NULL, RRA + target);
}

void rotate_stack(t_stack **stack, int x_rotate, int target_stack)
{
	// Command RX
	if (x_rotate > 0)
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RA + target_stack);
		// Command RRX
	if (x_rotate < 0)
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RRA + target_stack);
}


void	ft_move_number(t_stack **a, t_stack **b, t_command command)
{
	// If the both rotate in same direction
	if (command.a_rotate - command.b_rotate == 0)
	{
		// Command RR
		if (command.a_rotate > 0)
			ft_execute_command(a, b, RR);
		// Command RRR
		if (command.a_rotate < 0)
			ft_execute_command(a, b, RRR);
	}
	// If the rotate in opposite direction
	else
	{
		// Command RA - RRA
		if (command.a_rotate != 0)
			rotate_stack(a, command.a_rotate, STACK_A);
		// Command RB - RRB
		if (command.b_rotate != 0)
			rotate_stack(b, command.b_rotate, STACK_B);
	}
}


void	print_chipsets(t_stack **a, t_stack **b)
{
	t_stack		*current;
	int			index;
	int			n;
	t_command	chipset;
	t_command	perfect_chipset ;

	current = *a;
	index = 0;
	perfect_chipset.cost = INT_MAX;
	while (current)
	{
		n = current->n;
		chipset = ft_calculate_command(*a, index, *b, n);
		printf("\nCost of %d at index %d:\n    %d operation,   %d a_rotation,   %d b_rotation\n"
			, chipset.n, chipset.index, chipset.cost, chipset.a_rotate, chipset.b_rotate);
		if (chipset.cost < perfect_chipset.cost)
			perfect_chipset = chipset;
		current = current->next;
		index++;
		if (current == *a)
			break;
	}
	printf("\nPerfect Cost of %d at index %d:\n    %d operation,   %d a_rotation,   %d b_rotation\n"
			, perfect_chipset.n, perfect_chipset.index, perfect_chipset.cost, perfect_chipset.a_rotate, perfect_chipset.b_rotate);
	ft_move_number(a, b, perfect_chipset);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);

	//TODO Working in finding the perfect position 
	// display_stacks(a, b, "Before", "Command");
	ft_execute_command(&b, &a, PA);
	ft_execute_command(&b, &a, PA);
	// rotate_to_index(&a, 2, 0);
	// ft_execute_command(&a, NULL, SA);
	// ft_execute_command(&b, NULL, SB);
	display_stacks(a, b, "Before", "Command");

	//TODO I try to get the chipset of each number
	print_chipsets(&a, &b);
	display_stacks(a, b, "After", "Command");

}
