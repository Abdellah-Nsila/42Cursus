#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

// Basic Struct for stack
typedef struct s_stack
{
	int		n;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack ;

// Utils functions for double linked list
t_stack		*new(int n);
t_stack		*last(t_stack *stack);
void		push(t_stack **stack, t_stack *new);
t_stack		*pop(t_stack **stack);
int			stack_size(t_stack *stack);
t_stack		*generate_stack(char **arr, int size);
void		ft_clear(t_stack **stack);
void		ft_clear_arr(char **arr);

#endif 