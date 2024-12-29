/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:22:50 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 21:26:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../Libft/includes/libft.h"
# include "../Libft/includes/ft_printf.h"
# include "../Libft/includes/get_next_line.h"

# include "push_swap_utils.h"
# include "inputs.h"
# include "commands.h"
# include "calculations.h"
# include "execution.h"
# include "sorting.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

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

t_stack	*ft_init_stack(int ac, char **av);

#endif 
