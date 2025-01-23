/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/23 11:08:00 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool	ft_check_access(char *file, int permission) //  permission: R_OK  W_OK  X_OK
{
	if (access(file, permission) == -1)
		return (false);
	return (true);
}

t_bool	ft_parse_infile(t_pipex *pipex, char *infile)
{
	int fd;
	
	fd = open(infile, O_RDONLY);
	if (fd < 0 || ft_check_access(infile, R_OK) == false)
	{	
		ft_put_error(pipex, infile);
		ft_exit_on_error(pipex);
	}
	pipex->infile = ft_strdup(infile);
	pipex->infile_fd = fd;
	return (true);
}

// TODO you must chek the permission of each file ( already XD (: )) , and take descision
// TODO exit, print error, clean ...
t_bool	ft_parse_outfile(t_pipex *pipex, char *outfile)
{
	int flags;
	int fd;

	if (pipex->here_doc)
		flags = (O_WRONLY | O_CREAT | O_APPEND);
	else
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
	fd = open(outfile, flags);
	if (fd < 0 || ft_check_access(outfile, W_OK) == false)
		ft_put_error(pipex, outfile);
	pipex->outfile = ft_strdup(outfile);
	pipex->outfile_fd = fd;
	return (true);
}
