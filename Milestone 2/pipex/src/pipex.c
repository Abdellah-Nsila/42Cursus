/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/12 18:58:35 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->infile_fd = 0;
	pipex->oufile_fd = 0;
	pipex->here_doc = 0;
	pipex->is_invalid_infile = 0;
	pipex->cmd_envs = envp;
	pipex->infile = NULL;
	pipex->oufile = NULL;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex = malloc(sizeof(t_pipex));
	ft_init_pipex(pipex, argc, argv, envp);

	//TODO Need Parsing && Execution process && Clean up ... (0%)
	// ft_init_pipex(&pipex, argc, argv, envp);
	// ft_check_args(&pipex, argc, argv);
	// ft_parse_cmds(&pipex, envp);
	// ft_parse_args(&pipex, argv);
	// while (pipex.cmds)
	// 	ft_exec(&pipex);
	// ft_cleanup(&pipex);
	// return (0);
}
