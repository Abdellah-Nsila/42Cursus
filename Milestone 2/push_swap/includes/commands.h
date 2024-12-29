/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:22:38 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 21:22:39 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "push_swap_utils.h"

void		sa_sb(t_stack **stack);
void		ss(t_stack **a, t_stack **b);
void		pa_pb(t_stack **to_stack, t_stack **from_stack);
void		ra_rb_rra_rrb(t_stack **stack, int type);
void		rr_rrr(t_stack **a, t_stack **b, int type);

#endif 