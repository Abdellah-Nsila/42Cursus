/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 15:48:50 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
// {
// 	pipex->infile_fd = 0;
// 	pipex->oufile_fd = 0;
// 	pipex->here_doc = 0;
// 	pipex->limiter = "";
// 	pipex->is_invalid_infile = 0;
// 	pipex->cmd_envs = envp;
// 	pipex->infile = NULL;
// 	pipex->oufile = NULL;
// 	pipex->cmd_paths = NULL;
// 	pipex->cmd_args = NULL;
// 	pipex->cmd_count = 0;
// }

// $> ./pipex infile "ls -l" "wc -l" outfile
// $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// 1: infile , n: command,  n + 1: outfile







int ft_parse_commands(t_pipex *pipex, char **argv, int start, int end, char **envp)
{
	int i = 0;
	char	*path;

	pipex->cmd_count = end - start;
	pipex->cmd_paths = malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (!pipex->cmd_paths)
		return (0);
	while (start < end)
	{
		path = ft_get_path(argv[start], envp);
		if (ft_check_access(path, X_OK))
		{
			pipex->cmd_paths[i++] = path;
			printf("Command: %s X_OK\n", argv[start]);
		}
		else
		{
			free(path);
			perror("Error: Command");
			return (0);
		}
		start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (1);
}


int	ft_check_args(t_pipex *pipex, int argc, char **argv, char	**envp)
{
	int	i;

	if (!pipex)
		return (0);
	i = 1;
	if (i == 1 &&
		ft_strncmp("here_doc", argv[i], ft_strlen("here_doc")) == 0 &&
		argv[i])
	{
		i++;
		printf("Here_doc: %s\n", argv[i]);
		printf("Limiter: %s\n", argv[i]);
		pipex->here_doc = 1;
		pipex->limiter = ft_strdup(argv[i]);
		return (ft_parse_commands(pipex, argv, 3, argc - 1, envp) &&
		ft_parse_outfile(pipex, argv[argc - 1], 1));
	}
	else
	{
		pipex->infile = ft_strdup(argv[i]);
		return (ft_parse_commands(pipex, argv, 2, argc - 1, envp) &&
			ft_parse_infile(pipex, argv[1]) &&
			ft_parse_outfile(pipex, argv[argc - 1], 1));
	}
	// else if (i == 1 && ft_check_access(argv[i], R_OK))
	// {
	// 	printf("Infile: %s R_OK\n", argv[i]);
	// }
	// else if (i + 1 == argc && ft_check_access(argv[i], W_OK))
	// {
	// 	printf("Outfile: %s W_OK\n", argv[i]);
	// }
	// else if (ft_check_access(ft_get_path(argv[i], envp), X_OK))
	// {
	// 	printf("Command: %s X_OK\n", argv[i]);
	// }
}


int	main(int argc, char **argv, char **envp)
{
	int i = 0;
	if (!argc && argv && envp)
		return (1);
	t_pipex	*pipex = malloc(sizeof(t_pipex));
	// ft_init_pipex(pipex, argc, argv, envp);
	if (ft_check_args(pipex, argc, argv, envp))
	{
		while (pipex->cmd_paths[i])
		{
			printf("cmd_paths[%d]: %s\n",i, pipex->cmd_paths[i]);
			i++;
		}
	}
	free(pipex);

	//TODO Need Parsing && Execution process && Clean up ... (0%)
	// ft_init_pipex(&pipex, argc, argv, envp);
	// ft_check_args(&pipex, argc, argv);
	// ft_parse_cmds(&pipex, envp);
	// ft_parse_args(&pipex, argv);
	// while (pipex.cmds)
	// 	ft_exec(&pipex);
	// ft_cleanup(&pipex);
	// return (0);
}
