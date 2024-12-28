#ifndef EXECUTION_H
# define EXECUTION_H

# include "push_swap_utils.h"
# include "calculations.h"

void		ft_execute_command(t_stack **primary, t_stack **secondary, int type, int flag);
void		ft_run_perfect_rotation(t_stack **stack, int x_rotate, int target_stack);
void		ft_run_perfect_command(t_stack **a, t_stack **b, t_chipset command);

#endif 