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

void	ft_sort_three(t_stack **a)
{
	int flag;

	flag = 1;
	while ((*a)->n > (*a)->next->n || (*a)->next->n > (*a)->next->next->n)
	{
		if ((*a)->n > (*a)->next->n)
		{
			flag = 0;
			ft_execute_command(a, NULL, SA);
		}
		if ((*a)->next->n > (*a)->next->next->n)
		{
			flag = 0;
			ft_execute_command(a, NULL, RRA);
		}
	}
	
}

void rotate_stack(t_stack **stack, int x_rotate, int target_stack)
{
	// Command RX
	if (x_rotate > 0)
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RA + target_stack);
	// Command RRX
	else if (x_rotate < 0)
	{
		x_rotate = ABS(x_rotate);
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RRA + target_stack);
	}
}

void	ft_move_number(t_stack **a, t_stack **b, t_command command)
{
	int	type;

	// Execute Same direction command using RR || RRR
	if (command.a_rotate * command.b_rotate > 0)
	{
		if (command.a_rotate > 0)
			type =  RR;
		else
			type =  RRR;
		while (command.a_rotate && command.b_rotate)
		{
			ft_execute_command(a, b, type);
			// Adjust command.x_rotate: decrement for positive, increment for negative
			command.a_rotate -= 1 * ((command.a_rotate >= 0) * 2 - 1);  // command.a_rotate -= (1 || -1)
			command.b_rotate -= 1 * ((command.b_rotate >= 0) * 2 - 1);  // command.b_rotate -= (1 || -1)
		}
	}
	// Rest Command RA || RRA
	if (command.a_rotate != 0)
		rotate_stack(a, command.a_rotate, STACK_A);
	// Rest Command RB || RRB
	if (command.b_rotate != 0)
		rotate_stack(b, command.b_rotate, STACK_B);
	ft_execute_command(b, a, PB);
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		max;

	current = *a;
	max = ft_find_max(*a);

	// ft_execute_command(a, NULL, RRA);
	// ft_execute_command(a, b, PA);
	// ft_execute_command(a, b, PA);
	// ft_execute_command(a, b, PA);
	// ft_execute_command(a, b, PA);

	// ft_execute_command(a, NULL, RRA);
	// ft_execute_command(a, NULL, RRA);
	// ft_execute_command(a, b, PA);
	// ft_execute_command(a, b, PA);

	ft_execute_command(a, NULL, RRA);
	display_stacks(*a, *b, "After", "Command");

	// TODO Why the prev is not prev and current is not current XD ???
	while (stack_size(*b))
	{
		display_stacks(*a, *b, "After", "Command");
		printf("current: %d,   n: %d\n", current->n, (*b)->n); 
		while ((current->prev->n > (*b)->n && current->prev->n != max))
		{
			ft_execute_command(a, NULL, RRA);
		}
		ft_execute_command(a, b, PA);
	}
}

t_command	ft_get_perfect_chipset(t_stack *a, t_stack *b)
{
	t_stack		*current;
	int			index;
	int			n;
	t_command	chipset;
	t_command	perfect_chipset;

	current = a;
	index = 0;
	perfect_chipset.cost = INT_MAX;
	while (current)
	{
		n = current->n;
		chipset = ft_calculate_command(a, index, b, n);
		// print_chipset(chipset);
		if (chipset.cost < perfect_chipset.cost)
			perfect_chipset = chipset;
		current = current->next;
		index++;
		if (current == a || perfect_chipset.cost == 0)
			break;
	}
	// print_chipset(perfect_chipset);
	return (perfect_chipset);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_command	perfect_chipset;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (printf("Error\n"), 0);

	//TODO Working in finding the perfect position (100 %)
	display_stacks(a, b, "Before", "Command");

	ft_execute_command(&b, &a, PB);
	ft_execute_command(&b, &a, PB);

	//TODO I try to get the chipset of each number and return the perfect chipset (100 %)
	while (stack_size(a) > 3)
	{
		perfect_chipset = ft_get_perfect_chipset(a, b);
		ft_move_number(&a, &b, perfect_chipset);
		// display_stacks(a, b, "After", "Command");
	}

	//TODO I need to sort last three element in stack a (100 %)
	ft_sort_three(&a);

	//TODO Pushing back to STACK_A (0 %)
	ft_push_back(&a, &b);
	display_stacks(a, b, "After", "Command");

}
