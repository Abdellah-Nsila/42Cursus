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





void ft_close_parent_fds(t_pipex *pipex, int fd[2])
{
    close(fd[1]); // Close write end of the pipe
    if (pipex->infile_fd != -1) // Close infile_fd if it's open
        close(pipex->infile_fd);
    pipex->infile_fd = fd[0]; // Update infile_fd to the read end of the current pipe
}

void ft_execute_command(t_pipex *pipex, int cmd_index, int in_fd, int out_fd)
{
    (void)in_fd;
    (void)out_fd;

    if (execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], pipex->cmd_envs) == -1)
    {
        perror("execve error");
        ft_clean_pipex(pipex);
        exit(EXIT_FAILURE);
    }
}

void ft_run_commands(t_pipex *pipex)
{
    int fds[pipex->cmd_count - 1][2]; // Array to hold pipe fds
    int i;
    int pid;

    // Create pipes
    for (i = 0; i < pipex->cmd_count - 1; i++)
    {
        if (pipe(fds[i]) == -1)
        {
            perror("pipe error");
            ft_clean_pipex(pipex);
            exit(EXIT_FAILURE);
        }
    }

    // Create processes for each command
    for (i = 0; i < pipex->cmd_count; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork error");
            ft_clean_pipex(pipex);
            exit(EXIT_FAILURE);
        }

        if (pid == 0) // Child process
        {
            // Redirect input
            if (i == 0)
                dup2(pipex->infile_fd, STDIN_FILENO);
            else
                dup2(fds[i - 1][0], STDIN_FILENO);

            // Redirect output
            if (i == pipex->cmd_count - 1)
                dup2(pipex->outfile_fd, STDOUT_FILENO);
            else
                dup2(fds[i][1], STDOUT_FILENO);

            // Close all pipes in the child process
            for (int j = 0; j < pipex->cmd_count - 1; j++)
            {
                close(fds[j][0]);
                close(fds[j][1]);
            }

            // Execute command
            ft_execute_command(pipex, i, 0, 0);
        }
    }

    // Close all pipes in the parent process
    for (i = 0; i < pipex->cmd_count - 1; i++)
    {
        close(fds[i][0]);
        close(fds[i][1]);
    }

    // Wait for all child processes
    while (wait(NULL) > 0)
        ;
}

//TODO PLS organize this programme here, separate logic understand and test Mulptiple time
//TODO ensure error management, support of detecting error, same behavioure as SHELL
//TODO NO: open fds, leaks, crash (segf), terminal stuck, unxepted output, permission, no path, NULL, empty, gg\/glm0.."'" ..
//TODO add here_doc execution, clean code and dynamical update maintenace
int main(int argc, char **argv, char **envp)
{
    t_pipex *pipex;

    if (argc < 5)
    {
        fprintf(stderr, "Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n");
        return EXIT_FAILURE;
    }

    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
    {
        perror("malloc error");
        return EXIT_FAILURE;
    }

    ft_init_pipex(pipex, envp);

    if (!ft_parse_args(pipex, argc, argv, envp))
    {
        ft_clean_pipex(pipex);
        return EXIT_FAILURE;
    }

    ft_run_commands(pipex);
	ft_display_pipex(pipex);
    ft_clean_pipex(pipex);
    return EXIT_SUCCESS;
}
