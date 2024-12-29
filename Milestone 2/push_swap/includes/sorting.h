#ifndef SORTING_H
# define SORTING_H

# include "push_swap_utils.h"

// Sorting Functions
void	ft_sort_two(t_stack **a);
void	ft_sort_three(t_stack **a);
void    ft_sort_four(t_stack **a, t_stack **b);
int     ft_check_is_sorted(t_stack *stack);
void	ft_golden_nums(t_stack **a, t_stack **b);
void	ft_push_back(t_stack **a, t_stack **b);
void	ft_primary_sort(t_stack **a, t_stack **b);
void     ft_sort_stack(int ac, char **av);

#endif 