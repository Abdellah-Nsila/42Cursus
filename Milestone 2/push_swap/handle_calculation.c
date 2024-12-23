#include "push_swap.h"

int	ft_find_max(t_stack *stack)
{
	t_stack *current;
	int		max;

	current = stack;
	max = current->n;
	while (current)
	{
		if (current->n > max)
			max = current->n;
		current = current->next;
		if (current == stack)
			break;
	}
	return (max);
}

int	ft_find_min(t_stack *stack)
{
	t_stack *current;
	int     min;

	current = stack;
	min = current->n;
	while (current)
	{
		if (current->n < min)
			min = current->n;
		current = current->next;
		if (current == stack)
			break;
	}
	return (min);
}


int ft_find_position(t_stack *b, int num)
{
    t_stack *current;
    int index = 0;

    // Handle empty stack case
    if (!b)
        return 0;

    current = b;

    // Handle case where num is smaller than the smallest or larger than the largest
    do {
        if (num > current->n && num < current->next->n)
            return index + 1; // Found the position between two numbers
        current = current->next;
        index++;
    } while (current != b); // Loop through the circular stack

    // If not found, it means num is either the smallest or the largest
    // Place at the beginning or the end
	if (num < ft_find_min(b) || num > ft_find_max(b))
		return (0);
	else
		return (index);

}


// int	ft_find_position(t_stack *b, int n)
// {
// 	int	max;
// 	int	min;

// 	max = ft_find_max(b);
// 	min = ft_find_min(b);

// 	if (n < min)
// 	{

// 	}
// 	else if (n > max)
// 	{

// 	}

// 	t_stack *current;
// 	int		i;

// 	current = b;
// 	i = 0;
// 	while (current)
// 	{
// 		if (n < current->n && n > current->next->n)
// 			return (i + 1);
// 		current = current->next;
// 		i++;
// 		if (current == b)
// 			break;
// 	}
// }
