#ifndef DEBUGGING_H
# define DEBUGGING_H

# include "push_swap_utils.h"
# include "calculations.h"

void		print_node(t_stack *node);
void		print_stack(t_stack *stack);
void		display_stacks(t_stack *a, t_stack *b, char *state, char *action);
t_stack		*generate_stack(char **arr, int size);
t_stack		*generate_stack_test();
void		print_chipset(t_chipset chipset);

#endif 