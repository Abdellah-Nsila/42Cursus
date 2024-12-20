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

void	ft_print_node(t_node *node);
void	ft_print_stack(t_node *stack);
t_node	*ft_stack_last(t_node *stack);
t_node	*ft_stack_new(int n);
void	push(t_node **from_stack, t_node **to_stack);
t_node	*ft_stack_pop(t_node **stack);
void	ft_stack_rotate(t_node **stack);
void	ft_stack_reverse_rotate(t_node **stack);
void	ft_swap_node_content(t_node **stack);
void	ft_swap_real_node(t_node **stack);



// commands for push - swap - rotate
// handle inputs

#endif 