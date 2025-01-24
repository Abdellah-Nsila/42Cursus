/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:46:11 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/24 16:22:05 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return ;
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

// TODO You must fix this : export PATH=$PATH:/bin
//  % ./pipex  /dev/stdin cat ls  /dev/stdout
// 0x7ffc8dfa37c8
// zsh: Bad address
// zsh: Bad address: cat
// 0x7ffc8dfa37c8
// zsh: Bad address
// zsh: Bad address: ls
// a.out	fifoData  includes  Libft     outfile  PIPEX_TESTER  Test
// Backup	file	  infile    Makefile  pipex    src	     Todo.md

// === PIPEX STRUCT ===
// Infile FD: 4
// Outfile FD: 3
// Here_doc: Disabled
// Infile: /dev/stdin
// Outfile: /dev/stdout
// Is Invalid Infile: No
// Command Paths:
//   [0]: /usr/bin/cat
//   [1]: /usr/bin/ls
// Command Arguments:
//   Command 1 Args:
//     [0]: cat
//   Command 2 Args:
//     [0]: ls
// Environment Variables:
//     Env Exist
// Command Count: 2
// ====================
// abnsila@c4r2p5 ~/Desktop/42cursus/Milestone 2/pipex

char	*ft_get_path(t_pipex *pipex, char *command, char **envp)
{
	int		i;
	char	**all_path;
	char	*path;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	if (!envp[i])
	{
		ft_put_custom_error(pipex, command);
		return (ft_strdup(command));
	}
	all_path = ft_split(envp[i] + 5, ':');
	if (!all_path)
	{
		ft_put_custom_error(pipex, command);	
		return (ft_strdup(command));
	}
	path = ft_parse_path(all_path, command);
	if (ft_check_access(path, X_OK) == false)
			ft_put_custom_error(pipex, command);
	return (path);
}

t_bool	ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp)
{
	int		i;

	if (!pipex || !envp)
		return (false);
	i = 0;
	while (range.start < range.end && i < pipex->cmd_count)
	{
		if (pipex->cmd_args[i] && pipex->cmd_args[i][0])
		{
			if (ft_strchr(pipex->cmd_args[i][0], '/'))
			{
				if (ft_check_access(pipex->cmd_args[i][0], X_OK) == false)
					ft_put_error(pipex, pipex->cmd_args[i][0]);
				pipex->cmd_paths[i] =  ft_strdup(pipex->cmd_args[i][0]);
			}
			else
				pipex->cmd_paths[i] = ft_get_path(pipex,
										pipex->cmd_args[i][0], envp);
		}
		i++;
		range.start++;
	}
	pipex->cmd_paths[i] = NULL;
	return (true);
}
