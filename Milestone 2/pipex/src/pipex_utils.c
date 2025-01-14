/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/14 17:42:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **envp)
{
	if (!pipex)
		return;

	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;      
	pipex->here_doc = 0;
	pipex->is_invalid_infile = false;

	pipex->limiter = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_envs = envp;

	pipex->cmd_count = 0;
}

void	ft_reset_pipex(t_pipex *pipex)
{
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->here_doc = 0;
	pipex->is_invalid_infile = 0;
	pipex->cmd_count = 0;
	pipex->cmd_envs = NULL;
}
