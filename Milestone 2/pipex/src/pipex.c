/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 17:52:22 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// $> ./pipex infile "ls -l" "wc -l" outfile
// $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// 1: infile , n: command,  n + 1: outfile

char	**ft_get_cmd_arg(char **argv, int index)
{
	char	**cmd_args;

	cmd_args = ft_split(argv[index], ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
	
}

t_bool	ft_parse_cmd_args(t_pipex *pipex, char **argv, t_range range)
{
	int		i;
	char	**cmd_args;

	i = 0;
	pipex->cmd_count = range.end - range.start;
	pipex->cmd_args = (char ***)malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!pipex->cmd_args)
		return (false);
	while (range.start < range.end)
	{
		cmd_args = ft_get_cmd_arg(argv, range.start);
		if (!cmd_args)
		{
			// ft_free_count_array((void **)pipex->cmd_args, i);
			ft_free_2d_count_array(pipex, i);
			return (false);
		}
		pipex->cmd_args[i] = cmd_args;
		i++;
		range.start++;
	}
	pipex->cmd_args[i] = NULL;
	return (true);
}


t_bool	ft_parse_cmd_paths(t_pipex *pipex, char **argv, t_range range, char **envp)
{
	int 	i;
	char	*path;

	i = 0;
	//TODO unused parameter ‘argv’
	if (!argv)
		return (false);
	pipex->cmd_count = range.end - range.start;
	pipex->cmd_paths = malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (!pipex->cmd_paths)
		return (false);
	while (range.start < range.end)
	{
		path = ft_get_path(pipex->cmd_args[i][0], envp);
		if (ft_check_access(path, X_OK))
			pipex->cmd_paths[i++] = path;
		else
		{
			free(path);
			ft_free_count_array(pipex->cmd_paths, range.start);
			return (false);
		}
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (true);
}


t_bool	ft_check_args(t_pipex *pipex, int argc, char **argv, char	**envp)
{
	t_range	range;

	if (!pipex)
		return (false);
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
	{
		pipex->here_doc = 1;
		pipex->limiter = ft_strdup(argv[2]);
		range.start = 3;
		range.end = argc - 1;
		return (
			ft_parse_cmd_args(pipex, argv, range) &&
			ft_parse_cmd_paths(pipex, argv, range, envp) &&
			ft_parse_outfile(pipex, argv[argc - 1], 1)
			);
	}
	else
	{
		range.start = 2;
		range.end = argc - 1;
		return (
			ft_parse_cmd_args(pipex, argv, range) &&
			ft_parse_cmd_paths(pipex, argv, range, envp) &&
			ft_parse_infile(pipex, argv[1]) &&
			ft_parse_outfile(pipex, argv[argc - 1], 1)
			);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (!argc && argv && envp)
		return (1);
	t_pipex	*pipex = malloc(sizeof(t_pipex));
	ft_init_pipex(pipex, envp);
	ft_check_args(pipex, argc, argv, envp);

	// Display the struct (for testing)
    ft_display_pipex(pipex);
    // Clean up all allocated memory
    ft_clean_pipex(pipex);

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
