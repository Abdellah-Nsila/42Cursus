/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:17 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/14 12:08:47 by abnsila          ###   ########.fr       */
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
	char	*correct_path;

	i = 0;
	while (all_path[i])
	{
		temp = ft_strjoin("/", command);
		correct_path = ft_strjoin(all_path[i], temp);
		free(temp);
		if (correct_path && ft_check_access(correct_path, X_OK))
		{
			ft_free_array(all_path);
			return (correct_path);
		}
		free(correct_path);
		correct_path = NULL;
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

t_bool	ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **argv, char **envp)
{
	int  	i;
	char 	*path;
	t_bool	is_valid_args;

	if (ft_parse_cmd_args(pipex, argv, range) == false)
		return (false);
	i = 0;
	is_valid_args = true;
	while (range.start < range.end)
	{
		path = ft_get_path(pipex->cmd_args[i][0], envp);
		if (!path || !ft_check_access(path, X_OK))
		{
			dup2(STDERR_FILENO, STDOUT_FILENO);
			// ft_printf("command not found: %s\n", pipex->cmd_args[i][0]);
			ft_putstr_fd("%s: command not found\n", 2);
			ft_putstr_fd("%s: command not found\n", 2);
			path = NULL;
			is_valid_args = false;
			i++;
			range.start++;
			continue;
		}
		pipex->cmd_paths[i++] = path;
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (is_valid_args);
}
