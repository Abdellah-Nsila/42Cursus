/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/26 18:00:37 by abnsila          ###   ########.fr       */
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
		ft_exit_on_error(pipex, EXIT_FAILURE);
	else if (index > 0
		&& dup2(pipe_fds[index - 1][0], STDIN_FILENO) == -1)
		ft_exit_on_error(pipex, EXIT_FAILURE);
	if (index == pipex->cmd_count - 1)
	{
		ft_parse_outfile(pipex);
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
			ft_exit_on_error(pipex, EXIT_FAILURE);
	}
	else if (index < pipex->cmd_count - 1
		&& dup2(pipe_fds[index][1], STDOUT_FILENO) == -1)
		ft_exit_on_error(pipex, EXIT_FAILURE);
}

void	ft_execute_command(t_pipex *pipex, int cmd_index)
{
	if (execve(pipex->cmd_paths[cmd_index],
			pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
	{
		ft_put_error(pipex, pipex->cmd_args[cmd_index][0]);
		if (errno == ENOENT)
			ft_exit_on_error(pipex, 127);
		else if (errno == EACCES)
			ft_exit_on_error(pipex, 126);
		ft_exit_on_error(pipex, EXIT_FAILURE);
	}
}

int	ft_init_processes(t_pipex *pipex, int (*pipe_fds)[2])
{
	int	cmd_index;
	int	pid;

	cmd_index = 0;
	while (cmd_index < pipex->cmd_count)
	{
		pid = fork();
		if (pid == -1)
			return (pid);
		if (pid == 0)
		{
			ft_redirect_pipe_fds(pipex, pipe_fds, cmd_index);
			ft_close_pipes(pipex, pipe_fds);
			ft_execute_command(pipex, cmd_index);
			ft_exit_on_error(pipex, EXIT_FAILURE);
		}
		cmd_index++;
	}
	return (pid);
}

int	ft_run_commands(t_pipex *pipex)
{
	int		i;
	pid_t	w;
	int		status;
	int		last_pid;
	int		last_exit_code;

	if (!pipex->pipe_fds)
		return (EXIT_FAILURE);
	i = -1;
	last_exit_code = 0;
	while (++i < pipex->cmd_count - 1)
		if (pipe(pipex->pipe_fds[i]) == -1)
			return (EXIT_FAILURE);
	last_pid = ft_init_processes(pipex, pipex->pipe_fds);
	ft_close_pipes(pipex, pipex->pipe_fds);
	w = wait(&status);
	while (w > 0)
	{
		if (w == last_pid)
			if (WIFEXITED(status))
				last_exit_code = WEXITSTATUS(status);
		w = wait(&status);
	}
	return (last_exit_code);
}
