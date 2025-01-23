/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/23 18:54:11 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_pipes(t_pipex *pipex, int (*pipe_fds)[2])
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		close(pipe_fds[i][0]);
		close(pipe_fds[i][1]);
		i++;
	}
}

void	ft_redirect_pipe_fds(t_pipex *pipex, int (*pipe_fds)[2], int index)
{
	if (index == 0
		&& dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		ft_exit_on_error(pipex);
	else if (index > 0
		&& dup2(pipe_fds[index - 1][0], STDIN_FILENO) == -1)
		ft_exit_on_error(pipex);
	if (index == pipex->cmd_count - 1
		&& dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
		ft_exit_on_error(pipex);
	else if (index < pipex->cmd_count - 1
		&& dup2(pipe_fds[index][1], STDOUT_FILENO) == -1)
		ft_exit_on_error(pipex);
}

void	ft_execute_command(t_pipex *pipex, int cmd_index)
{
	if (execve(pipex->cmd_paths[cmd_index],
			pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
	{
		ft_exit_on_error(pipex);
	}
}

void	ft_init_processes(t_pipex *pipex, int (*pipe_fds)[2])
{
	int	cmd_index;
	int	pid;

	cmd_index = 0;
	while (cmd_index < pipex->cmd_count)
	{
		pid = fork();
		if (pid == -1)
			return ;
		if (pid == 0)
		{
			ft_redirect_pipe_fds(pipex, pipe_fds, cmd_index);
			ft_close_pipes(pipex, pipe_fds);
			ft_execute_command(pipex, cmd_index);
			ft_exit_on_error(pipex);
		}
		cmd_index++;
	}
}

void	ft_run_commands(t_pipex *pipex)
{
	int	i;

	if (!pipex->pipe_fds)
		return ;
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(pipex->pipe_fds[i]) == -1)
			return ;
		i++;
	}
	ft_init_processes(pipex, pipex->pipe_fds);
	ft_close_pipes(pipex, pipex->pipe_fds);
	while (wait(NULL) > 0)
		;
}
