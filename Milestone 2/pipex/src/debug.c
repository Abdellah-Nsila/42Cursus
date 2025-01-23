/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:16:05 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/23 15:53:01 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_display_pipex(const t_pipex *pipex)
{
	int i, j;

	if (!pipex)
	{
		printf("Pipex struct is NULL.\n");
		return;
	}

	printf("=== PIPEX STRUCT ===\n");
	printf("Infile FD: %d\n", pipex->infile_fd);
	printf("Outfile FD: %d\n", pipex->outfile_fd);
	printf("Here_doc: %s\n", pipex->here_doc ? "Enabled" : "Disabled");
	if (pipex->here_doc && pipex->limiter)
		printf("Limiter: %s\n", pipex->limiter);
	printf("Infile: %s\n", pipex->infile ? pipex->infile : "NULL");
	printf("Outfile: %s\n", pipex->outfile ? pipex->outfile : "NULL");
	printf("Is Invalid Infile: %s\n", pipex->is_invalid_infile ? "Yes" : "No");

	// Display command paths
	printf("Command Paths:\n");
	if (pipex->cmd_paths)
	{
		for (i = 0; pipex->cmd_paths[i]; i++)
			printf("  [%d]: %s\n", i, pipex->cmd_paths[i]);
	}
	else
	{
		printf("  NULL\n");
	}

	// Display command arguments
	printf("Command Arguments:\n");
	if (pipex->cmd_args)
	{
		for (i = 0; i < pipex->cmd_count; i++)
		{
			printf("  Command %d Args:\n", i + 1);
			for (j = 0; pipex->cmd_args[i][j]; j++)
				printf("    [%d]: %s\n", j, pipex->cmd_args[i][j]);
		}
	}
	else
		printf("  NULL\n");

	// Display environment variables
	printf("Environment Variables:\n");
	if (pipex->cmd_envs)
		printf("    Env Exist\n");
	else
		printf("    NULL\n");
	//? If you want to display all envp
	// if (pipex->cmd_envs)
	// {
	//     for (i = 0; pipex->cmd_envs[i]; i++)
	//         printf("  [%d]: %s\n", i, pipex->cmd_envs[i]);
	// }
	// else
	// {
	//     printf("  NULL\n");
	// }

	printf("Command Count: %d\n", pipex->cmd_count);
	printf("====================\n");
}


// TODO Some tests
// valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./pipex non_exist_input "cat /dev/random"  wc  /dev/stdout