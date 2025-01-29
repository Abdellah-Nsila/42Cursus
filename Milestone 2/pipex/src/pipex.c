/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:48:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/29 12:27:07 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_check_parse(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("Usage [1]: ./pipex file1 \
cmd1 cmd2 cmd3 ... cmdn file2\n", STDERR_FILENO);
		ft_putstr_fd("Usage [2]: ./pipex here_doc LIMITER cmd cmd1 file\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0
		&& ft_strlen("here_doc") == ft_strlen(argv[1]) && argc < 6)
	{
		ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd cmd1 file\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc < 5)
	{
		ft_putstr_fd("Usage [1]: ./pipex file1 \
cmd1 cmd2 cmd3 ... cmdn file2\n", STDERR_FILENO);
		ft_putstr_fd("Usage [2]: ./pipex here_doc LIMITER cmd cmd1 file\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		exit_code;

	ft_check_parse(argc, argv);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	ft_init_pipex(pipex, envp);
	if (!ft_parse_args(pipex, argc, argv, envp))
		ft_exit_on_error(pipex, EXIT_FAILURE);
	exit_code = ft_run_commands(pipex);
	ft_exit_on_success(pipex, exit_code);
}
