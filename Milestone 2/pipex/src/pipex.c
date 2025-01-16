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


// t_bool	ft_check_empty_arg(char ***arg)
// {

// }

// int	ft_execution_child(t_pipex *pipex, int i, int input_fd)
// {
// 	int	pipe_fd[2];
// 	int pid;

// 	// Validate command before executing
// 	if (!pipex->cmd_paths[i] || !pipex->cmd_args[i][0])
// 	{
// 		printf("Error: Invalid command at position %d\n", i + 1);
// 		return (input_fd);
// 	}

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		printf("Error in creating pipe\n");
// 		exit(1); 
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		printf("Error in forking\n");
// 	if (pid == 0)
// 	{
// 		dup2(input_fd, STDIN_FILENO);
// 		if (i == pipex->cmd_count - 1)
// 			dup2(pipex->outfile_fd, STDOUT_FILENO);
// 		else
// 			dup2(pipe_fd[1], STDOUT_FILENO);
//         close(pipe_fd[0]);
//         close(pipe_fd[1]);
// 		if (execve(pipex->cmd_paths[i], pipex->cmd_args[i], pipex->cmd_envs) == -1)
// 			return (2);
// 	}
// 	close(pipe_fd[1]);
// 	if (input_fd != pipex->infile_fd)
// 		close(input_fd);
// 	int status;
// 	waitpid(pid, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
// 	{
// 		printf("Command failed with status %d\n", WEXITSTATUS(status));
// 		exit(1);
// 	}
// 	printf("Command Run Successfully\n");
// 	// printf("Command: %s\n", pipex->cmd_paths[i]);
// 	// printf("input_fd: %d,  out_fd: %d\n", input_fd, pipe_fd[1]);
// 	return (pipe_fd[0]);
// }


// int	main(int argc, char **argv, char **envp)
// {
// 	int	i;
// 	int	input_fd;

// 	if (argc < 5)
// 		return (1);

// 	// Init Pipex Struct
// 	t_pipex	*pipex = malloc(sizeof(t_pipex));
// 	ft_init_pipex(pipex, envp);

// 	// Parse && Check Argument
// 	if (ft_parse_args(pipex, argc, argv, envp) == false)
// 	{
// 		// printf("Error\n");
// 		// ft_display_pipex(pipex);
// 		ft_clean_pipex(pipex);
// 		return (1);
// 	}

// 	// Execution
// 	i = 0;
// 	input_fd = pipex->infile_fd;
// 	while (pipex && i < pipex->cmd_count)
// 	{
// 		input_fd =  ft_execution_child(pipex, i, input_fd);
// 		if (input_fd == -1)
// 			break ;
// 		i++;
// 	}

// 	// printf("\n\n\nSuccess\n");
// 	// ft_display_pipex(pipex);
// 	ft_clean_pipex(pipex);

// 	//TODO Need Parsing && Execution process && Clean up ... (0%)
// 	// ft_init_pipex(&pipex, argc, argv, envp);
// 	// ft_check_args(&pipex, argc, argv);
// 	// ft_parse_cmds(&pipex, envp);
// 	// ft_parse_args(&pipex, argv);
// 	// while (pipex.cmds)
// 	// 	ft_exec(&pipex);
// 	// ft_cleanup(&pipex);
// 	return (0);
// }


void	ft_execute_command(t_pipex *pipex, int cmd_index, int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(EXIT_FAILURE);
	}
	// Close unused file descriptors
	close(in_fd);
	close(out_fd);

	// Execute the command
	if (execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		fd[2];
	int		i, pid;

	if (argc < 5)
		return (1);

	// Init Pipex Struct
	pipex = malloc(sizeof(t_pipex));
	ft_init_pipex(pipex, envp);

	// Parse && Check Argument
	if (ft_parse_args(pipex, argc, argv, envp) == false)
	{
		// printf("Error\n");
		// ft_display_pipex(pipex);
		ft_clean_pipex(pipex);
		return (1);
	}

	// TODO Execute commands
	i = 0;
	while (i < pipex->cmd_count)
	{
		if (i < pipex->cmd_count - 1 && pipe(fd) == -1) // Create pipe
		{
			perror("pipe error");
			return (1);
		}

		pid = fork(); // Create child process
		if (pid == -1)
		{
			perror("fork error");
			return (1);
		}

		if (pid == 0) // Child process
		{
			if (i == 0) // First command
				ft_execute_command(pipex, i, pipex->infile_fd, fd[1]);
			else if (i == pipex->cmd_count - 1) // Last command
				ft_execute_command(pipex, i, fd[0], pipex->outfile_fd);
			else // Middle command
				ft_execute_command(pipex, i, fd[0], fd[1]);
		}

		// Parent process
		close(fd[1]); // Close write end of the pipe
		if (i > 0)    // Close previous pipe's read end
			close(pipex->infile_fd);
		i++;
	}

	// Wait for all child processes
	while (wait(NULL) > 0);
	ft_clean_pipex(pipex);
	return (0);
}
