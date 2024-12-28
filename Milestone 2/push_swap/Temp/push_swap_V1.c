#include "../../includes/push_swap.h"

t_stack	*generate_stack(char **arr, int size)
{
	t_stack	*head;
	t_stack	*new_node;

	head = NULL;
	while (size--)
	{
		new_node = new(ft_atoi(arr[size]));
		if (!new_node)
			return (NULL);
		push(&head, new_node);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;

	b = NULL;
	a = ft_init_stack(ac, av);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ft_check_is_sorted(a))
		return (ft_clear(&a), 1);
	size_a = stack_size(a);
	if (size_a == 2)
		ft_sort_two(&a);
	else if (size_a == 3)
		ft_sort_three(&a);
	else if (size_a == 4)
		ft_sort_four(&a, &b);
	else
		ft_primary_sort(&a, &b);
	ft_clear(&a);
	ft_clear(&b);
}




// //TODO You must push the two min number to stack b, after that sort stack a, and then just push back simply => ./push_swap "2 1 3 4 5"
// void ft_push_min_to_b(t_stack **a, t_stack **b)
// {
//     t_stack *current;
//     int min;
//     int pos;
//     int i;

//     current = *a;
//     min = current->n;
//     pos = 0;
//     i = 0;

//     // Find the smallest element and its position
// 	ft_printf("cur: %d\n", (*a)->n);
//     while (current)
//     {
//         if (current->n < min)
//         {
//             min = current->n;
//             pos = i;
//         }
//         current = current->next;
// 		if (current->next == *a)
// 			break;
//         i++;
//     }

//     // Rotate or reverse rotate to bring the smallest to the top
//     ft_run_perfect_rotation(a, pos, STACK_A);
// 	ft_execute_command(b, a, PB, 1);
// }

// void ft_sort_four_or_five(t_stack **a, t_stack **b)
// {
//     while (stack_size(*a) > 3)
//         ft_push_min_to_b(a, b);
//     ft_sort_three(a);
//     ft_push_back(a, b);
// }



// int main(int ac, char **av)
// {
// 	t_stack *a;
// 	t_stack *b;
// 	int		size_a;

// 	b = NULL;
// 	a = ft_init_stack(ac, av);
// 	if (!a)
// 		return (ft_putstr_fd("Error\n", 2), 0);
// 	if (ft_check_is_sorted(a))
// 		return (ft_clear(&a), 0);
// 	size_a = stack_size(a);
// 	if (size_a == 2)
// 	ft_sort_two(&a);
// 	else if (size_a == 3)
// 		ft_sort_three(&a);
// 	else if (size_a == 4 || size_a == 5)
//     	ft_sort_four_or_five(&a, &b);
// 	else
// 		ft_primary_sort(&a, &b);

// 	ft_clear(&a);
// 	ft_clear(&b);
// }

