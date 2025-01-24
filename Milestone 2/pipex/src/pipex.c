/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:48:18 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/24 18:11:21 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"




int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	ft_check_parse(argc, argv);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit(EXIT_FAILURE);
	ft_init_pipex(pipex, envp);
	if (!ft_parse_args(pipex, argc, argv, envp))
		ft_exit_on_error(pipex);
	ft_run_commands(pipex);
	// ft_display_pipex(pipex);
	ft_exit_on_success(pipex);
}
