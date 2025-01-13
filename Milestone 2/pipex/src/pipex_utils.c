/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 18:41:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **envp)
{
	if (!pipex)
		return;

	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;      
	pipex->here_doc = 0;
	pipex->is_invalid_infile = 0;

	pipex->limiter = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_envs = envp;

	pipex->cmd_count = 0;
}

void	ft_freearray(char **arr)
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

	i = 0;
	if (!arr)
		return;
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

// void	ft_reset_pipex(t_pipex *pipex)
// {

// }

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
	ft_free_count_array(pipex->cmd_paths, pipex->cmd_count);
	ft_free_2d_count_array(pipex, pipex->cmd_count);
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->here_doc = 0;
	pipex->is_invalid_infile = 0;
	pipex->cmd_count = 0;
	free(pipex);
}

