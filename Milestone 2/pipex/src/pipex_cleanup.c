/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:03:02 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/14 18:49:22 by abnsila          ###   ########.fr       */
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
				printf("pipex->cmd_args[%d][%d]: %s\n",i, j, pipex->cmd_args[i][j]);
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
	
	if (pipex->limiter)
	{
		free(pipex->limiter);
		pipex->limiter = NULL;
	}
	if (pipex->infile)
	{
		free(pipex->infile);
		pipex->infile = NULL;
	}
	if (pipex->outfile)
	{
		free(pipex->outfile);
		pipex->outfile = NULL;
	}
	if (pipex->cmd_paths)
	{
		ft_free_count_array(pipex->cmd_paths, pipex->cmd_count);
		pipex->cmd_paths = NULL;
	}
	if (pipex->cmd_args)
	{
		ft_free_2d_count_array(pipex, pipex->cmd_count);
		pipex->cmd_args = NULL;
	}
	free(pipex);
}

