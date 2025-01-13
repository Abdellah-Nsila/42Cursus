/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:43:12 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/13 16:22:00 by abnsila          ###   ########.fr       */
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

char	**ft_free_count_array(char **arr, size_t count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (NULL);
}

char	**ft_freearray(char **arr)
{
	int	i;

	i = 0; 
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

