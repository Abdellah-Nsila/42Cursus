/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:07:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/19 12:37:56 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_put_error(t_pipex *pipex, char *error, char *command)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf(error, pipex->shell, command);
	ft_printf("\n");
}

void	ft_exit_on_error(t_pipex *pipex)
{
	if (pipex)
		ft_clean_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	ft_command_error(t_pipex *pipex, char *command)
{
	if (ft_strchr(command, '/'))
		ft_put_error(pipex, "%s : no such file or directory: %s", command);
	else
		ft_put_error(pipex, "%s : command not found: %s", command);
}

