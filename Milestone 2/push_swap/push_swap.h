#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
#include "./Libft/libft.h"


// handle double linked list
// commands for push - swap - rotate

typedef struct s_node
{
	int n;
	struct s_node   *prev;
	struct s_node   *next;
}	t_node ;

void	print_node(t_node *node);
void	print_stack(t_node *stack);
t_node	*new(int n);
t_node	*last(t_node *stack);
void	push(t_node **stack, t_node *new);
t_node	*pop(t_node **stack);

void	sa_sb(t_node **stack);
void	ss(t_node **a, t_node **b);
void	pa_pb(t_node **from_stack, t_node **to_stack);
void	ra_rb_rra_rrb(t_node **stack, char type);
void	rr_rrr(t_node **a, t_node **b, char type);

// handle inputs

#endif 