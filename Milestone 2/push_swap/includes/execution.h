/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:22:43 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 21:25:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "push_swap_utils.h"
# include "calculations.h"

typedef struct s_command
{
	t_stack		**a;
	t_stack		**b;
	int			type;
	int			flag;
	const char	*command;
}	t_command;

t_command	ft_init_commands(t_stack **a, t_stack **b, int type, int flag);
void		ft_execute_single_stack(t_stack **s, int t, int f, const char *c);
void		ft_execute_dual_stack(t_command *cmd);
void		ft_execute_command(t_stack **a, t_stack **b, int type, int flag);
void		ft_run_perfect_rotation(t_stack **a, t_stack **b,
				int x_rotate, int target_stack);
void		ft_run_perfect_command(t_stack **a, t_stack **b, t_chipset command);

#endif 