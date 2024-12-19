#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

// handle double linked list

typedef struct s_node 
{
	int n;
	struct s_node   *prev;
	struct s_node   *next;
}	t_node ;

void	ft_print_node(t_node *node);
void	ft_print_lst(t_node *lst);
t_node	*ft_lst_last(t_node *lst);
t_node	*ft_lst_new(int n);
void	ft_lst_add_front(t_node **lst, t_node *new);
t_node	*ft_lst_pop(t_node **lst);
void	ft_lst_rotate(t_node **lst);
void	ft_lst_reverse_rotate(t_node **lst);
void	ft_swap_node_content(t_node **lst);
void	ft_swap_real_node(t_node **lst);



// commands for push - swap - rotate
// handle inputs

#endif 