#ifndef COMMANDS_H
# define COMMANDS_H

# include "push_swap_utils.h"

// Push_Swap Cammands
void		sa_sb(t_stack **stack);
void		ss(t_stack **a, t_stack **b);
void		pa_pb(t_stack **to_stack, t_stack **from_stack);
void		ra_rb_rra_rrb(t_stack **stack, int type);
void		rr_rrr(t_stack **a, t_stack **b, int type);

#endif 