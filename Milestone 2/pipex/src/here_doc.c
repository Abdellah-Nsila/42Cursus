/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:06:56 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/29 12:40:26 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_generate_tmpfile(t_pipex *pipex)
{
	char	*temp;

	temp = ft_itoa(getpid());
	if (!temp)
	{
		pipex->infile = ft_strdup("/tmp/pipex_heredoc");
		return ;
	}
	pipex->infile = ft_strjoin("/tmp/pipex_heredoc_", temp);
	free(temp);
}

void	ft_fill_here_doc(t_pipex *pipex, int fd)
{
	char	*line;
	size_t	line_size;

	while (1)
	{
		ft_printf("here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_printf("\n");
			break ;
		}
		line_size = ft_strlen(line) - 1;
		if (ft_strncmp(line, pipex->limiter,
				ft_strlen(pipex->limiter)) == 0
			&& line_size == ft_strlen(pipex->limiter))
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}

void	ft_here_doc(t_pipex *pipex)
{
	int		fd;

	ft_generate_tmpfile(pipex);
	fd = open(pipex->infile, (O_WRONLY | O_CREAT | O_TRUNC), 0777);
	if (fd < 0)
		ft_format_error(pipex, "%s: %s: %s", strerror(errno), pipex->infile);
	else
		ft_fill_here_doc(pipex, fd);
}
