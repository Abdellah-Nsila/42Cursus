/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:17 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 15:42:20 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

