/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:06:44 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/17 12:22:18 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_parse_default_path(char *command)
{
	char	*correct_path;

	correct_path = ft_strjoin("/usr/bin/", command);
	if (correct_path && ft_check_access(correct_path, X_OK))
		return (correct_path);
	free(correct_path);
	correct_path = NULL;
	return (NULL);
}

char	*ft_parse_path(char	**all_path, char *command)
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	while (all_path[i])
	{
		temp = ft_strjoin("/", command);
		path = ft_strjoin(all_path[i], temp);
		free(temp);			
		if (path && ft_check_access(path, X_OK))
		{
			ft_free_array(all_path);
			return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	ft_free_array(all_path);
	return (command);
}

char    *ft_get_path(char *command, char **envp)
{
	int		i;
	char	**all_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	all_path = ft_split(envp[i], ':');
	if (!all_path)
		return (command);
	return (ft_parse_path(all_path, command));
}

t_bool	ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp)
{
	int  	i;
	// char 	*command;
	char 	*path;

	i = 0;
	pipex->cmd_paths = (char **) malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (pipex->cmd_paths)
	{	
		while (i <= pipex->cmd_count)
			pipex->cmd_paths[i++] = NULL;
	}
	i = 0;
	while (range.start < range.end)
	{
		// command = ft_strdup(pipex->cmd_args[i][0]);
		path = ft_get_path(pipex->cmd_args[i][0], envp);
		if (!path)
		{
			path = NULL;
			i++;
			range.start++;
			continue;
		}
		pipex->cmd_paths[i++] = ft_strdup(path);
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (true);
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
			ft_clean_pipex(pipex);
			return (1);
		}

		pid = fork(); // Create child process
		if (pid == -1)
		{
			perror("fork error");
			if (i > 0) close(fd[0]); // Close previous read end
			ft_clean_pipex(pipex);
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
		// if (i > 0)    // Close previous pipe's read end
		close(pipex->infile_fd);
		
		pipex->infile_fd = fd[0]; // Carry over read end for the next command
		i++;
	}

	// Wait for all child processes
	while (wait(NULL) > 0);

	// Cleanup
	ft_clean_pipex(pipex);
	return (0);
}



// // Function to close file descriptors in the parent process
// void ft_close_parent_fds(t_pipex *pipex, int fd[2])
// {
// 	close(fd[1]);
// 	close(pipex->infile_fd);
// 	pipex->infile_fd = fd[0];
// }

// // t_bool	ft_check_empty_arg(char ***arg)
// // {

// // }


// void	ft_execute_command(t_pipex *pipex, int cmd_index, int in_fd, int out_fd)
// {
// 	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2 error");
// 		ft_clean_pipex(pipex);
// 		exit(EXIT_FAILURE);
// 	}
// 	// Close unused file descriptors
// 	close(in_fd);
// 	close(out_fd);

// 	// Execute the command
// 	if (execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
// 	{
// 		perror("execve error");
// 		ft_clean_pipex(pipex);
// 		exit(EXIT_FAILURE);
// 	}
// }

// // Function to handle child process logic
// void ft_init_processes(t_pipex *pipex, int cmd_index, int fd[2])
// {
// 	printf("index: %d,  fd[0]: %d   fd[1]: %d\n", cmd_index, fd[0], fd[1]);
// 	if (cmd_index == 0)
// 		ft_execute_command(pipex, cmd_index, pipex->infile_fd, fd[1]);
// 	else if (cmd_index == pipex->cmd_count - 1)
// 		ft_execute_command(pipex, cmd_index, fd[0], pipex->outfile_fd);
// 	else
// 		ft_execute_command(pipex, cmd_index, fd[0], fd[1]);
// }

// //TODO FIX This < /dev/stdin cat | cat | grep aa > outfile
// // Function to initialize processes and execute commands
// void ft_run_commands(t_pipex *pipex)
// {
// 	int fd[2];
// 	int i;
// 	int pid;

// 	i = 0;
// 	while (i < pipex->cmd_count)
// 	{
// 		printf("i: %d, count: %d\n", i , pipex->cmd_count);
// 		if (i < pipex->cmd_count - 1 && pipe(fd) == -1)
// 		{
// 			perror("pipe error");
// 			ft_clean_pipex(pipex);
// 			exit(EXIT_FAILURE);
// 		}
// 		pid = fork();
// 		if (pid == -1)
// 		{
// 			perror("fork error");
// 			if (i > 0)
// 				close(fd[0]);
// 			ft_clean_pipex(pipex);
// 			exit(EXIT_FAILURE);
// 		}
// 		if (pid == 0)
// 			ft_init_processes(pipex, i, fd);
// 		// wait(NULL);
// 		i++;
// 	}
// 	ft_close_parent_fds(pipex, fd);
// 	while (wait(NULL) > 0);
// }



// int	main(int argc, char **argv, char **envp)
// {
// 	t_pipex *pipex;

// 	if (argc < 5)
// 		return (EXIT_FAILURE);
// 	pipex = malloc(sizeof(t_pipex));
// 	if (!pipex)
// 		return (EXIT_FAILURE);

// 	ft_init_pipex(pipex, envp);

// 	if (ft_parse_args(pipex, argc, argv, envp) == false)
// 		return (ft_clean_pipex(pipex), EXIT_FAILURE);
// 	ft_run_commands(pipex);
// 	ft_clean_pipex(pipex);
// 	return (EXIT_SUCCESS);
// }

