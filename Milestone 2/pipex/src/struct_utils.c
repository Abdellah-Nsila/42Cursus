/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:40:47 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/26 14:46:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit_on_success(t_pipex *pipex, int exit_code)
{
	if (pipex->here_doc)
		unlink(pipex->infile);
	ft_clean_pipex(pipex);
	exit(exit_code);
}

void	ft_init_pipex(t_pipex *pipex, char **envp)
{
	if (!pipex)
		return ;
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->here_doc = 0;
	pipex->limiter = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_envs = envp;
	pipex->pipe_fds = NULL;
	pipex->shell = NULL;
	pipex->cmd_count = 0;
}

void	ft_reset_pipex(t_pipex *pipex)
{
	if (pipex->infile_fd >= 0)
	{
		close(pipex->infile_fd);
		pipex->infile_fd = -1;
	}
	if (pipex->outfile_fd >= 0)
	{
		close(pipex->outfile_fd);
		pipex->outfile_fd = -1;
	}
	pipex->here_doc = 0;
	pipex->cmd_count = 0;
	pipex->cmd_envs = NULL;
}

void	ft_free_pipe_fds(t_pipex *pipex)
{
	if (pipex->pipe_fds)
	{
		ft_close_pipes(pipex, pipex->pipe_fds);
		free(pipex->pipe_fds);
		pipex->pipe_fds = NULL;
	}
}

void	ft_reset_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
