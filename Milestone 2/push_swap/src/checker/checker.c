#include "../../includes/checker.h"

int	ft_get_command(char *command)
{
	int i;
	const char *commands[10];

	commands[SA] = "sa\n";
	commands[SB] = "sb\n";
	commands[PA] = "pa\n";
	commands[PB] = "pb\n";
	commands[RA] = "ra\n";
	commands[RB] = "rb\n";
	commands[RRA] = "rra\n";
	commands[RRB] = "rrb\n";
	commands[RR] = "rr\n";
	commands[RRR] = "rrr\n";

	i = 0;
	while (i < 10)
	{
		if (ft_strncmp(command, commands[i], ft_strlen(command)) == 0)
			return i;
		i++;
	}
	return (-1);
}

void	ft_read_instructions(t_stack **a, t_stack **b)
{
	char	*line;
	int		command_type;

	line = get_next_line(0);
	while (line)
	{
		command_type = ft_get_command(line);
		free(line);
		if (command_type == -1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_clear(a);
			ft_clear(b);
			exit(1);
		}
		ft_execute_command(a, b, command_type, 0);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac == 1)
		return (0);
	a = ft_init_stack(ac, av);
	if (!a)
		exit(1);
	b = NULL;

	ft_read_instructions(&a, &b);

	if (ft_check_is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n", 1);
	ft_clear(&a);
	ft_clear(&b);
	exit(0);
}
