#include "../../includes/push_swap.h"

void	ft_execute_command(t_stack **primary, t_stack **secondary, int type, int flag)
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
	if (flag)
		printf("%s\n", commands[type]);
}

void	ft_run_perfect_rotation(t_stack **stack, int x_rotate, int target_stack)
{
	// Command RX
	if (x_rotate > 0)
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RA + target_stack, 1);
	// Command RRX
	else if (x_rotate < 0)
	{
		x_rotate = ABS(x_rotate);
		while (x_rotate-- > 0)
			ft_execute_command(stack, NULL, RRA + target_stack, 1);
	}
}

void	ft_run_perfect_command(t_stack **a, t_stack **b, t_command command)
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
			ft_execute_command(a, b, type, 1);
			// Adjust command.x_rotate: decrement for positive, increment for negative
			command.a_rotate -= 1 * ((command.a_rotate >= 0) * 2 - 1);  // command.a_rotate -= (1 || -1)
			command.b_rotate -= 1 * ((command.b_rotate >= 0) * 2 - 1);  // command.b_rotate -= (1 || -1)
		}
	}
	// Rest Command RA || RRA
	if (command.a_rotate != 0)
		ft_run_perfect_rotation(a, command.a_rotate, STACK_A);
	// Rest Command RB || RRB
	if (command.b_rotate != 0)
		ft_run_perfect_rotation(b, command.b_rotate, STACK_B);
	ft_execute_command(b, a, PB, 1);
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
		if (chipset.cost < perfect_chipset.cost)
			perfect_chipset = chipset;
		current = current->next;
		index++;
		if (current == a || perfect_chipset.cost == 0)
			break;
	}
	return (perfect_chipset);
}
