/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 13:44:50 by abnsila          ###   ########.fr       */
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
int	ft_check_access(char *file, int permission) //  permission: R_OK  W_OK  X_OK
{
	if (access(file, permission) == -1)
		return (0);
	return (1);
}

char	**ft_freearray(char **arr)
{
	int	i;

	i = 0; 
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	ft_check_input_file(char *file)
{
	if (access(file, R_OK) == -1)
	{
		perror("Error: Input file");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_output_file(char *file)
{
	int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error: Output file");
		exit(EXIT_FAILURE);
	}
	close(fd);
}


char	*ft_parse_default_path(char *command)
{
	char	*correct_path;

	correct_path = ft_strjoin("/usr/bin/", command);
	if (correct_path && ft_check_access(correct_path, X_OK))
		return (correct_path);
	return (NULL);
}

char	*ft_parse_path(char	**all_path, char *command)
{
	int		i;
	char	*temp;
	char	*correct_path;

	i = 0;
	while (all_path[i])
	{
		temp = ft_strjoin("/", command);
		correct_path = ft_strjoin(all_path[i], temp);
		free(temp);
		if (correct_path && ft_check_access(correct_path, X_OK))
		{
			ft_freearray(all_path);
			return (correct_path);
		}
		free(correct_path);
		i++;
	}
	correct_path = ft_parse_default_path(command);
	ft_freearray(all_path);
	return (correct_path);
}

char *ft_get_path(char *command, char **envp)
{
	int		i;
	char	**all_path;
	char	*correct_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	all_path = ft_split(envp[i], ':');
	if (!all_path)
	{
		correct_path = ft_parse_default_path(command);
		return (correct_path);
	}
	return (ft_parse_path(all_path, command));
}



int	ft_check_args(t_pipex **pipex, int argc, char **argv, char	**envp)
{
	int	i;

	if (!pipex)
		return (0);
	i = 1;
	// Todo manage parsing and paralelle argument flow, and split necacary command,
	// Todo and store those proriete in the pipex struct after checking all unit 
	// Todo of globall command (parametres), ... any idea ? XD 
	while (i < argc)
	{
		if (i == 1 && ft_strncmp("here_doc", argv[i], ft_strlen("here_doc")) == 0)
		{
			printf("Here_doc: %s\n", argv[i]);
			i++;
			if (argv[i])
			printf("Limiter: %s\n", argv[i]);
		}
		else if (i == 1 && ft_check_access(argv[i], R_OK))
		{
			printf("Infile: %s R_OK\n", argv[i]);
		}
		else if (i + 1 == argc && ft_check_access(argv[i], W_OK))
		{
			printf("Outfile: %s W_OK\n", argv[i]);
		}
		else if (ft_check_access(ft_get_path(argv[i], envp), X_OK))
		{
			printf("Command: %s X_OK\n", argv[i]);
		}
		i++;
	}
	return (1);
}


int	main(int argc, char **argv, char **envp)
{
	char	*correct_path;
	// int i = 0;
	if (!argc && argv && envp)
		return (1);
	t_pipex	*pipex = malloc(sizeof(t_pipex));
	// ft_init_pipex(pipex, argc, argv, envp);
	ft_check_args(&pipex, argc, argv, envp);
	correct_path = ft_get_path("cat", envp);
	printf("correct_path: %s\n", correct_path);
	free(correct_path);
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
