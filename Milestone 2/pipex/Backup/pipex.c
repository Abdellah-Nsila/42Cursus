/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:31:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/17 18:34:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
// /*   Updated: 2025/01/16 12:02:36 by abnsila          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/pipex.h"

// $> ./pipex infile "ls -l" "wc -l" outfile
// $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// 1: infile , n: command,  n + 1: outfile

void	ft_exit_on_error(t_pipex *pipex, char *error)
{
	if (error)
		perror(error);
	if (pipex)
		ft_clean_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	ft_close_pipes(t_pipex *pipex, int (*fds)[2])
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}
	free(fds);
}

void	ft_redirect_fds(t_pipex *pipex, int (*fds)[2], int index)
{
	if (index == 0)
		dup2(pipex->infile_fd, STDIN_FILENO);
	else
		dup2(fds[index - 1][0], STDIN_FILENO);
	if (index == pipex->cmd_count - 1)
		dup2(pipex->outfile_fd, STDOUT_FILENO);
	else
		dup2(fds[index][1], STDOUT_FILENO);
}

void ft_execute_command(t_pipex *pipex, int cmd_index)
{
	if (execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
	{
		// perror("execve error");
		// ft_clean_pipex(pipex);
		// exit(EXIT_FAILURE);
		ft_exit_on_error(pipex, "execve error");
	}
}

void	ft_init_processes(t_pipex *pipex, int (*fds)[2])
{
	int	cmd_index;
	int	pid;

	cmd_index = 0;
	while (cmd_index < pipex->cmd_count)
	{
		pid = fork();
		if (pid == -1)
		{
			// perror("fork error");
			// ft_clean_pipex(pipex);
			// exit(EXIT_FAILURE);
			ft_exit_on_error(pipex, "fork error");
		}
		if (pid == 0)
		{
			ft_redirect_fds(pipex, fds, cmd_index);
			ft_close_pipes(pipex, fds);
			ft_execute_command(pipex, cmd_index);
		}
		cmd_index++;
	}
}

void	ft_run_commands(t_pipex *pipex)
{
	int	(*fds)[2];
	int	i;

	fds = ft_calloc(pipex->cmd_count - 1, sizeof(int[2]));
	if (!fds)
	{
		// ft_clean_pipex(pipex);
		// exit(EXIT_FAILURE);
		ft_exit_on_error(pipex, NULL);
	}
	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(fds[i]) == -1)
		{
			free(fds);
			// perror("pipe error");
			// ft_clean_pipex(pipex);
			// exit(EXIT_FAILURE);
			ft_exit_on_error(pipex, "pipe error");
		}
		i++;
	}
	ft_init_processes(pipex, fds);
	ft_close_pipes(pipex, fds);
	while (wait(NULL) > 0)
		;
}


//TODO PLS organize this programme here, separate logic understand and test Mulptiple time
//TODO ensure error management, support of detecting error, same behavioure as SHELL
//TODO NO: open fds, leaks, crash (segf), terminal stuck, unexepted output, permission, no path, NULL, empty, gg\/glm0.."'" ..
//TODO add here_doc execution, clean code and dynamical update maintenace
int main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;

	if (argc < 5)
	{
		// perror("Bad argument, Ex: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
		// return (EXIT_FAILURE);
		ft_exit_on_error(NULL,
			"Bad argument, Ex: ./pipex file1 \
			cmd1 cmd2 cmd3 ... cmdn file2\n");
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	ft_init_pipex(pipex, envp);
	if (!ft_parse_args(pipex, argc, argv, envp))
		// return (ft_clean_pipex(pipex), EXIT_FAILURE);
		ft_exit_on_error(pipex, NULL);
	ft_run_commands(pipex);
	ft_display_pipex(pipex);
	ft_clean_pipex(pipex);
	exit(EXIT_SUCCESS);
}
