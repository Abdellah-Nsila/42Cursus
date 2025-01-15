/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:01 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/15 15:43:57 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// $> ./pipex infile "ls -l" "wc -l" outfile
// $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
// 1: infile , n: command,  n + 1: outfile



int	main(int argc, char **argv, char **envp)
{
	if (!argc && argv && envp)
		return (1);
	t_pipex	*pipex = malloc(sizeof(t_pipex));
	ft_init_pipex(pipex, envp);
	if (ft_check_args(pipex, argc, argv, envp) == false)
	{
		printf("Error\n");
		ft_display_pipex(pipex);
		ft_clean_pipex(pipex);
		return (1);
	}

	// Display the struct (for testing)
	printf("Success\n");
	ft_display_pipex(pipex);
	ft_clean_pipex(pipex);

	//TODO Need Parsing && Execution process && Clean up ... (0%)
	// ft_init_pipex(&pipex, argc, argv, envp);
	// ft_check_args(&pipex, argc, argv);
	// ft_parse_cmds(&pipex, envp);
	// ft_parse_args(&pipex, argv);
	// while (pipex.cmds)
	// 	ft_exec(&pipex);
	// ft_cleanup(&pipex);
	return (0);
}
