/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:41:19 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/25 15:23:04 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_bool	ft_check_access(char *file, int permission)
{
	if (access(file, permission) == -1)
		return (false);
	return (true);
}

t_bool	ft_parse_infile(t_pipex *pipex, char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0 || ft_check_access(infile, (R_OK | F_OK)) == false)
		ft_format_error(pipex, "%s: %s: %s", strerror(errno), infile);
	if (pipex->infile == NULL)
		pipex->infile = ft_strdup(infile);
	pipex->infile_fd = fd;
	return (true);
}

t_bool	ft_parse_outfile(t_pipex *pipex, char *outfile)
{
	int	flags;
	int	fd;

	if (pipex->here_doc)
		flags = (O_WRONLY | O_CREAT | O_APPEND);
	else
		flags = (O_WRONLY | O_CREAT | O_TRUNC);
	fd = open(outfile, flags, 0644);
	if (fd < 0 || ft_check_access(outfile, W_OK) == false)
		ft_format_error(pipex, "%s: %s: %s", strerror(errno), outfile);
	pipex->outfile = ft_strdup(outfile);
	pipex->outfile_fd = fd;
	return (true);
}
