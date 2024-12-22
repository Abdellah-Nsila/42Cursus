#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include "./Libft/libft.h"

// Basic Struct for stack
typedef struct s_node
{
	int n;
	struct s_node   *prev;
	struct s_node   *next;
}	t_node ;

// Some functions for debugging
void	print_node(t_node *node);
void	print_stack(t_node *stack);
void	display_stacks(t_node *a, t_node *b, char *state, char *action);
t_node	*genarate_stack();

// Utils functions for double linked list
t_node	*new(int n);
t_node	*last(t_node *stack);
void	push(t_node **stack, t_node *new);
t_node	*pop(t_node **stack);

// Push_Swap Cammands
void	sa_sb(t_node **stack);
void	ss(t_node **a, t_node **b);
void	pa_pb(t_node **from_stack, t_node **to_stack);
void	ra_rb_rra_rrb(t_node **stack, char type);
void	rr_rrr(t_node **a, t_node **b, char type);

//Todo Functions to handle inputs
int		ft_check_numbers(char **arr, int size);
int		ft_validate_arg(int ac, char **av);

#endif 