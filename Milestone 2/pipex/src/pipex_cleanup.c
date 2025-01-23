/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:03:02 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/23 10:37:55 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_array(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0; 
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_count_array(char **arr, int count)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (i < count)
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_2d_array(t_pipex *pipex)
{
	int	i;
	int	j;

	if (!pipex || !pipex->cmd_args)
		return;
	i = 0;
	while (i < pipex->cmd_count)
	{
		if (pipex->cmd_args[i])
		{
			j = 0;
			while (pipex->cmd_args[i][j])
			{
				free(pipex->cmd_args[i][j]);
				pipex->cmd_args[i][j] = NULL;
				j++;
			}
			free(pipex->cmd_args[i]);
			pipex->cmd_args[i] = NULL;
		}
		i++;
	}
	free(pipex->cmd_args);
	pipex->cmd_args = NULL;
}

void	ft_free_2d_count_array(t_pipex *pipex, int count)
{
	int	i;
	int	j;

	if (!pipex || !pipex->cmd_args)
		return;
	i = 0;
	while (i < count)
	{
		if (pipex->cmd_args[i])
		{
			j = 0;
			while (pipex->cmd_args[i][j])
			{
				free(pipex->cmd_args[i][j]);
				pipex->cmd_args[i][j] = NULL;
				j++;
			}
			free(pipex->cmd_args[i]);
			pipex->cmd_args[i] = NULL;
		}
		i++;
	}
	free(pipex->cmd_args);
	pipex->cmd_args = NULL;
}

void	ft_clean_pipex(t_pipex *pipex)
{
	if (!pipex)
		return;
	ft_reset_ptr(pipex->limiter);
	ft_reset_ptr(pipex->infile);
	ft_reset_ptr(pipex->outfile);
	ft_reset_ptr(pipex->shell);
	ft_free_pipe_fds(pipex);
	ft_free_count_array(pipex->cmd_paths, pipex->cmd_count);
	ft_free_2d_count_array(pipex, pipex->cmd_count);
	ft_reset_pipex(pipex);
	free(pipex);
	pipex = NULL;
}
