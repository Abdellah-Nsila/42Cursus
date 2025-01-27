/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:07:03 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/27 09:58:59 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_format_error(t_pipex *pipex, char *format, char *error, char *arg)
{
	char	buffer[1024];

	ft_bzero(buffer, sizeof(buffer));
	if (!pipex || !format || !error)
		return ;
	if (pipex->shell)
		ft_strlcat(buffer, pipex->shell, sizeof(buffer));
	ft_strlcat(buffer, ": ", sizeof(buffer));
	ft_strlcat(buffer, error, sizeof(buffer));
	if (arg)
	{
		ft_strlcat(buffer, ": ", sizeof(buffer));
		ft_strlcat(buffer, arg, sizeof(buffer));
	}
	ft_strlcat(buffer, "\n", sizeof(buffer));
	write(STDERR_FILENO, buffer, ft_strlen(buffer));
}

void	ft_put_error(t_pipex *pipex, char *arg)
{
	if (!arg)
		ft_format_error(pipex, "%s: %s: %s", "command not found", " ");
	else if (ft_strchr(arg, '/'))
		ft_format_error(pipex, "%s: %s: %s", strerror(errno), arg);
	else
		ft_format_error(pipex, "%s: %s: %s", "command not found", arg);
}

void	ft_exit_on_error(t_pipex *pipex, int exit_code)
{
	if (pipex)
		ft_clean_pipex(pipex);
	exit(exit_code);
}
