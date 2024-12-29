/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:22:45 by abnsila           #+#    #+#             */
/*   Updated: 2024/12/29 21:22:46 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "push_swap_utils.h"

t_stack		*ft_handle_string(char **av);
int			ft_validate_arg(char **arr, int size);

#endif 
