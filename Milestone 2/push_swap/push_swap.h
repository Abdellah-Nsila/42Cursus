#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include "./Libft/libft.h"

# define bool int
# define TRUE 1
# define FALSE 0

enum command
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
};

// Basic Struct for stack
typedef struct s_stack
{
	int		n;
	// int		cheapest;
	struct s_stack   *prev;
	struct s_stack   *next;
}	t_stack ;

// Some functions for debugging
void	print_node(t_stack *node);
void	print_stack(t_stack *stack);
void	display_stacks(t_stack *a, t_stack *b, char *state, char *action);
t_stack	*generate_stack(char **arr, int size);
t_stack	*generate_stack_test();

// Utils functions for double linked list
t_stack	*new(int n);
t_stack	*last(t_stack *stack);
void	push(t_stack **stack, t_stack *new);
t_stack	*pop(t_stack **stack);
int		stack_size(t_stack *stack);

// Push_Swap Cammands
void	sa_sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	pa_pb(t_stack **to_stack, t_stack **from_stack);
void	ra_rb_rra_rrb(t_stack **stack, int type);
void	rr_rrr(t_stack **a, t_stack **b, int type);

// Functions to handle inputs
int		ft_validate_arg(char **arr, int size);
t_stack	*ft_init_stack(int ac, char **av);

//Todo Calculation functions
int		ft_calculate_rotate(t_stack *stack, int index);
int		ft_calculate_top_max(t_stack *stack, int max);
int		ft_calculate_b_rotate(t_stack *stack, int n);

//Todo Helper functions to track sorting (push, rotate, ...) in correct position 
int		ft_find_max(t_stack *stack);
int		ft_find_min(t_stack *stack);
int		ft_find_position(t_stack *b, int n);

#endif 