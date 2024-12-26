#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include "../Libft/includes/libft.h"
#include "../Libft/includes/ft_printf.h"
#include "../Libft/includes/get_next_line.h"

// # define bool int
// # define TRUE 1
// # define FALSE 0

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ABS(nbr) ((nbr) * ((nbr >= 0) * 2 - 1))

enum stack
{
	STACK_A,
	STACK_B,
};

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

typedef struct s_command
{
	int n;
	int	index;
	int a_rotate;
	int b_rotate;
	int cost;
} t_command;

// Basic Struct for stack
typedef struct s_stack
{
	int		n;
	// int		cheapest;
	struct s_stack   *prev;
	struct s_stack   *next;
}	t_stack ;

// Some functions for debugging
void		print_node(t_stack *node);
void		print_stack(t_stack *stack);
void		display_stacks(t_stack *a, t_stack *b, char *state, char *action);
t_stack		*generate_stack(char **arr, int size);
t_stack		*generate_stack_test();
void		print_chipset(t_command chipset);

// Utils functions for double linked list
t_stack		*new(int n);
t_stack		*last(t_stack *stack);
void		push(t_stack **stack, t_stack *new);
t_stack		*pop(t_stack **stack);
int			stack_size(t_stack *stack);

// Push_Swap Cammands
void		sa_sb(t_stack **stack);
void		ss(t_stack **a, t_stack **b);
void		pa_pb(t_stack **to_stack, t_stack **from_stack);
void		ra_rb_rra_rrb(t_stack **stack, int type);
void		rr_rrr(t_stack **a, t_stack **b, int type);

// Functions to handle inputs
int			ft_validate_arg(char **arr, int size);
t_stack		*ft_init_stack(int ac, char **av);

//Todo Calculation functions
int			ft_calculate_rotate(t_stack *stack, int index);
int			ft_calculate_top_max(t_stack *stack, int max);
int			ft_calculate_b_rotate(t_stack *stack, int n);
t_command	ft_calculate_command(t_stack *a, int index, t_stack *b, int n);
t_command	ft_get_perfect_chipset(t_stack *a, t_stack *b);


//Todo Helper functions to track sorting (push, rotate, ...) in correct position
int			ft_find_index(t_stack *stack, int max);
int			ft_find_max(t_stack *stack);
int			ft_find_min(t_stack *stack);

// Execution functions
void		ft_execute_command(t_stack **primary, t_stack **secondary, int type, int flag);
void		ft_run_perfect_rotation(t_stack **stack, int x_rotate, int target_stack);
void		ft_run_perfect_command(t_stack **a, t_stack **b, t_command command);

// Sorting Functions
void		ft_sort_two(t_stack **a);
void		ft_sort_three(t_stack **a);
void		ft_sort_four(t_stack **a, t_stack **b);
int			ft_check_is_sorted(t_stack *stack);
void		ft_push_back(t_stack **a, t_stack **b);
void		ft_primary_sort(t_stack **a, t_stack **b);

#endif 
