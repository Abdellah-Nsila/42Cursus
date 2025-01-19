/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:59:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/19 11:19:27 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool	ft_init_cmd_struct_arr(t_pipex *pipex)
{
	int	i;

	if (!pipex)
		return (false);
	i = 0;
	pipex->cmd_args = (char ***) malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (pipex->cmd_args)
	{
		while (i <= pipex->cmd_count)
			pipex->cmd_args[i++] = NULL;
	}
	i = 0;
	pipex->cmd_paths = (char **) malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (pipex->cmd_paths)
	{	
		while (i <= pipex->cmd_count)
			pipex->cmd_paths[i++] = NULL;
	}
	pipex->pipe_fds = ft_calloc(pipex->cmd_count - 1, sizeof(int[2]));
	return (true);
}

t_bool	ft_check_parse_format(int argc, char **argv)
{
	int	i;

	if (argc < 5)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			return (false);
		i++;
	}
	return (true);
}

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

	pipex->cmd_count = range.end - range.start;
	if (ft_init_cmd_struct_arr(pipex) == false)
		return (false);
	i = 0;
	while (range.start < range.end)
	{
		cmd_args = ft_get_cmd_arg(argv, range.start);
		if (!cmd_args)
			return (false);
		pipex->cmd_args[i] = cmd_args;
		i++;
		range.start++;
	}
	pipex->cmd_args[i] = NULL;
	return (true);
}

t_bool	ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp)
{
	t_range	range;

	if (!pipex)
		return (false);
	range.end = argc - 1;
	ft_get_shell(pipex, envp);
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
	{
		range.start = 3;
		pipex->here_doc = 1;
		pipex->limiter = ft_strdup(argv[2]);
		return (
			ft_parse_cmd_args(pipex, argv, range) &&
			ft_parse_cmd_paths(pipex, range, envp) &&
			ft_parse_outfile(pipex, argv[argc - 1]));
	}
	else
	{
		range.start = 2;
		return (
			ft_parse_cmd_args(pipex, argv, range) &&
			ft_parse_cmd_paths(pipex, range, envp) &&
			ft_parse_infile(pipex, argv[1]) &&
			ft_parse_outfile(pipex, argv[argc - 1]));
	}
}
