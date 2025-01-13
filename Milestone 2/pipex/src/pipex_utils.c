/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 17:59:51 by abnsila          ###   ########.fr       */
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

void	ft_free_count_array(char **arr, size_t count)
{
	if (!arr)
		return;
	while (count > 0)
	{
		count--;
		if (arr[count])
		{
			free(arr[count]);
			arr[count] = NULL;
		}
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
	int	j;

	if (!pipex || !pipex->cmd_args)
		return;
	while (count > 0)
	{
		count--;
		if (pipex->cmd_args[count])
		{
			j = 0;
			while (pipex->cmd_args[count][j])
			{
				free(pipex->cmd_args[count][j]);
				pipex->cmd_args[count][j] = NULL;
				j++;
			}
			free(pipex->cmd_args[count]);
			pipex->cmd_args[count] = NULL;
		}
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
	ft_freearray(pipex->cmd_paths);
	ft_free_2d_array(pipex);
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->here_doc = 0;
	pipex->is_invalid_infile = 0;
	pipex->cmd_count = 0;
	free(pipex);
}

