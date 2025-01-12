/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/12 16:31:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include "../Libft/includes/libft.h"

void	ft_close_fds(int (*fd)[2], int i);
void	ft_printnums(int n);
int		power(int n, int power);
int     ft_n_sum(int *arr, int start, int size);

#endif 