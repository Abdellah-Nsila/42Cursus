#ifndef CALCULATIONS_H
# define CALCULATIONS_H

# include "push_swap_utils.h"

typedef struct s_chipset
{
	int n;
	int	index;
	int a_rotate;
	int b_rotate;
	int cost;
} t_chipset;

//Helper functions to track sorting (push, rotate, ...) in correct position
int			ft_find_index(t_stack *stack, int max);
int			ft_find_max(t_stack *stack);
int			ft_find_min(t_stack *stack);

//Calculation functions
int			ft_calculate_rotate(t_stack *stack, int index);
int			ft_calculate_top_max(t_stack *stack, int max);
int			ft_calculate_b_rotate(t_stack *stack, int n);
t_chipset	ft_calculate_command(t_stack *a, int index, t_stack *b, int n);
t_chipset	ft_get_perfect_chipset(t_stack *a, t_stack *b);

#endif 