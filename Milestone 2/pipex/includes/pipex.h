/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 15:51:53 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include "../Libft/includes/libft.h"


typedef struct	s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	t_bool	here_doc;
	char	*limiter;
	t_bool	is_invalid_infile;
	char	*infile;
	char	*outfile;
	char	**cmd_paths;
	char	***cmd_args;
	char	**cmd_envs;
	int		cmd_count;
}	t_pipex;

void	ft_close_fds(int (*fd)[2], int i);
void	ft_printnums(int n);
int		power(int n, int power);
int		ft_n_sum(int *arr, int start, int size);

#endif 