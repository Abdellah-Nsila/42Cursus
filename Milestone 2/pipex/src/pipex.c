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


// Function to close file descriptors in the parent process
void ft_close_parent_fds(t_pipex *pipex, int fd[2])
{
    close(fd[1]);
    close(pipex->infile_fd);
    pipex->infile_fd = fd[0];
}

// t_bool	ft_check_empty_arg(char ***arg)
// {

// }


void	ft_execute_command(t_pipex *pipex, int cmd_index, int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		ft_clean_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	// Close unused file descriptors
	close(in_fd);
	close(out_fd);

	// Execute the command
	if (execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
	{
		perror("execve error");
		ft_clean_pipex(pipex);
		exit(EXIT_FAILURE);
	}
}

// Function to handle child process logic
void ft_init_processes(t_pipex *pipex, int cmd_index, int fd[2])
{
    if (cmd_index == 0)
        ft_execute_command(pipex, cmd_index, pipex->infile_fd, fd[1]);
    else if (cmd_index == pipex->cmd_count - 1)
        ft_execute_command(pipex, cmd_index, fd[0], pipex->outfile_fd);
    else
        ft_execute_command(pipex, cmd_index, fd[0], fd[1]);
}

// Function to initialize processes and execute commands
void ft_run_commands(t_pipex *pipex)
{
    int fd[2];
    int i;
    int pid;

    i = 0;
    while (i < pipex->cmd_count)
    {
        if (i < pipex->cmd_count - 1 && pipe(fd) == -1)
        {
            perror("pipe error");
            ft_clean_pipex(pipex);
            exit(EXIT_FAILURE);
        }
        pid = fork();
        if (pid == -1)
        {
            perror("fork error");
            if (i > 0)
                close(fd[0]);
            ft_clean_pipex(pipex);
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
            ft_init_processes(pipex, i, fd);
        ft_close_parent_fds(pipex, fd);
        i++;
    }
    while (wait(NULL) > 0);
}


//TODO FIX This < /dev/stdin cat | cat | grep aa > outfile
int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;

    if (argc < 5)
        return (EXIT_FAILURE);
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return (EXIT_FAILURE);

    ft_init_pipex(pipex, envp);

    if (ft_parse_args(pipex, argc, argv, envp) == false)
        return (ft_clean_pipex(pipex), EXIT_FAILURE);
    ft_run_commands(pipex);
    ft_clean_pipex(pipex);
    return (EXIT_SUCCESS);
}

