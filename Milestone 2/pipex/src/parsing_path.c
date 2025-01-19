// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsing_path.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/13 15:41:17 by abnsila           #+#    #+#             */
// /*   Updated: 2025/01/14 19:02:44 by abnsila          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_get_shell(t_pipex *pipex, char **envp)
{
	int		i;
	char	*shell_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHELL=", 6) == 0)
		{
			shell_path = envp[i] + 6;
			pipex->shell = ft_strdup(ft_strrchr(shell_path, '/') + 1);
			if (!pipex->shell)
				break ;
			return;
		}
		i++;
	}
	pipex->shell = ft_strdup("sh");
	if (!pipex->shell)
		ft_exit_on_error(pipex);
}

char	*ft_parse_path(char **all_path, char *command)
{
	int		i;
	char	*temp;
	char	*path;
	char	*result;

	i = 0;
	result = NULL;
	while (all_path[i] && !result)
	{
		temp = ft_strjoin("/", command);
		if (!temp)
			break ;
		path = ft_strjoin(all_path[i], temp);
		free(temp);
		if (path && ft_check_access(path, X_OK))
			result = path;
		else
			free(path);
		i++;
	}
	ft_free_array(all_path);
	if (!result)
		result = ft_strdup(command);
	return (result);
}

char	*ft_get_path(char *command, char **envp)
{
	int		i;
	char	**all_path;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (!envp[i])
		return (ft_strdup(command));
	all_path = ft_split(envp[i] + 5, ':');
	if (!all_path)
		return (ft_strdup(command));
	path = ft_parse_path(all_path, command);
	return (path);
}

t_bool	ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp)
{
	int		i;
	char	*path;

	if (!pipex || !envp)
		return (false);
	i = 0;
	while (range.start < range.end && i < pipex->cmd_count)
	{
		if (pipex->cmd_args[i] && pipex->cmd_args[i][0])
		{
			path = ft_get_path(pipex->cmd_args[i][0], envp);
			if (path)
				pipex->cmd_paths[i] = path;
			else
				pipex->cmd_paths[i] = ft_strdup("");
		}
		else
			pipex->cmd_paths[i] = ft_strdup("");
		if (ft_check_access(pipex->cmd_paths[i], X_OK) == false)
			ft_command_error(pipex, pipex->cmd_args[i][0]);
		i++;
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (true);
}
