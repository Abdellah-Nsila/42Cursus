#include "../../includes/push_swap.h"

// Just for debeugging
void	print_node(t_stack *node)
{
	printf("|                     Node Members                     |\n");
	printf("| n:    %d                                              |\n", node->n);
	// printf("| prev: %p                                 |\n", node->prev);
	// printf("| next: %p                                 |\n", node->next);
	printf("|______________________________________________________|\n");

}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		printf("|                   List is empty !                    |\n");
		printf("|______________________________________________________|\n");
		return ;
	}
	current = stack;
	do {
		 print_node(current);
		current = current->next;
	} while (current != stack);
}

void	display_stacks(t_stack *a, t_stack *b, char *state, char *action)
{
	printf("\n======================== %s %s ========================\n", state, action);
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^ Stack a ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(a);
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^ Stack b ^^^^^^^^^^^^^^^^^^^^^^^^\n");
	print_stack(b);
}





int	ft_check_is_sorted(t_stack *stack){
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->next == stack)
			break;
		if (current->n > current->next->n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	while (stack_size(*b))
	{
		if ((*b)->n < ft_find_min(*a) || (*b)->n > ft_find_max(*a))
		{
			int min_index = ft_find_index(*a, ft_find_min(*a));
			ft_run_perfect_rotation(a, ft_calculate_rotate(*a, min_index), STACK_A);
		}
		else
		{
			while ((*a)->prev->n > (*b)->n)
				ft_execute_command(a, NULL, RRA, 1);
		}
		ft_execute_command(a, b, PA, 1);
		// display_stacks(*a, *b, "After", "Push Back");
	}
	int min_index = ft_find_index(*a, ft_find_min(*a));
	ft_run_perfect_rotation(a, ft_calculate_rotate(*a, min_index), STACK_A);
	// display_stacks(*a, *b, "After", "Final Sort");

}

void	ft_primary_sort(t_stack **a, t_stack **b)
{
	t_command	perfect_chipset;

	ft_execute_command(b, a, PB, 1);
	ft_execute_command(b, a, PB, 1);

	// I try to get the chipset of each number and return the perfect chipset
	while (stack_size(*a) > 3)
	{
		perfect_chipset = ft_get_perfect_chipset(*a, *b);
		ft_run_perfect_command(a, b, perfect_chipset);
	}

	// Sort last three element in stack A
	ft_sort_three(a);

	// Pushing back to STACK_A (assending order)
	ft_push_back(a, b);
}
