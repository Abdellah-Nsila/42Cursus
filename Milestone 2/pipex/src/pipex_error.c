/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:07:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/23 11:00:52 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_format_error(t_pipex *pipex, char *format, char *error, char *arg)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf(format, pipex->shell, error, arg);
	ft_printf("\n");
}

void	ft_exit_on_error(t_pipex *pipex)
{
	if (pipex)
		ft_clean_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	ft_put_error(t_pipex *pipex, char *arg)
{
	ft_format_error(pipex, "%s: %s: %s", strerror(errno), arg);
}

