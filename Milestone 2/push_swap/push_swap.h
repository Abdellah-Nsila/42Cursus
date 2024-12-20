#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
#include "./Libft/libft.h"


// handle double linked list

typedef struct s_node
{
	int n;
	struct s_node   *prev;
	struct s_node   *next;
}	t_node ;

void	print_node(t_node *node);
void	print_stack(t_node *stack);
t_node	*last(t_node *stack);
t_node	*new(int n);
void	push(t_node **stack, t_node *new);
t_node	*pop(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	swap(t_node **stack);
void	put(t_node **from_stack, t_node **to_stack);
// void	swap_node_content(t_node **stack);



// commands for push - swap - rotate
// handle inputs

#endif 