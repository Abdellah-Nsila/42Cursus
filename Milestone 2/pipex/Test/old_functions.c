/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:06:44 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/14 19:06:47 by abnsila          ###   ########.fr       */
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

