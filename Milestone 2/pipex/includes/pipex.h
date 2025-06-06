/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnsila <abnsila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:45:07 by abnsila           #+#    #+#             */
/*   Updated: 2025/01/26 17:54:43 by abnsila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <errno.h>

# include "../Libft/includes/libft.h"

// Begin && End indexs range of Commands inside the argv array
typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

// Pipex struct
typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	t_bool	here_doc;
	char	*limiter;
	char	*infile;
	char	*outfile;
	char	**cmd_paths;
	char	***cmd_args;
	char	**cmd_envs;
	int		(*pipe_fds)[2];
	int		cmd_count;
	char	*shell;
}	t_pipex;

// Pipex Utils
void		ft_exit_on_success(t_pipex *pipex, int exit_code);
void		ft_init_pipex(t_pipex *pipex, char **envp);
void		ft_reset_pipex(t_pipex *pipex);
void		ft_free_pipe_fds(t_pipex *pipex);
void		ft_reset_ptr(void *ptr);

// Parse files
t_bool		ft_check_access(char *file, int permission);
t_bool		ft_parse_infile(t_pipex *pipex, char *infile);
t_bool		ft_parse_outfile(t_pipex *pipex);

// Parse Path
void		ft_get_shell(t_pipex *pipex, char **envp);
char		*ft_parse_path(char	**all_path, char *command);
char		*ft_get_path(t_pipex *pipex, char *command, char **envp);
t_bool		ft_parse_cmd_paths(t_pipex *pipex, t_range range, char **envp);

// Parse Arguments
void		ft_check_parse(int argc, char **argv);
t_bool		ft_init_cmd_struct_arr(t_pipex *pipex);
t_bool		ft_parse_args(t_pipex *pipex, int argc, char **argv, char **envp);
char		**ft_get_cmd_arg(char **argv, int index);
t_bool		ft_parse_cmd_args(t_pipex *pipex, char **argv, t_range range);

// Here_doc
void		ft_generate_tmpfile(t_pipex *pipex);
void		ft_fill_here_doc(t_pipex *pipex, int fd);
void		ft_here_doc(t_pipex *pipex);

// Execution functions
void		ft_close_pipes(t_pipex *pipex, int (*pipe_fds)[2]);
void		ft_redirect_pipe_fds(t_pipex *pipex, int (*pipe_fds)[2], int index);
void		ft_execute_command(t_pipex *pipex, int cmd_index);
int			ft_init_processes(t_pipex *pipex, int (*pipe_fds)[2]);
int			ft_run_commands(t_pipex *pipex);

// Clean up functions
void		ft_free_array(char **arr);
void		ft_free_count_array(char **arr, int count);
void		ft_free_2d_count_array(t_pipex *pipex, int count);
void		ft_clean_pipex(t_pipex *pipex);

// Errors
void		ft_format_error(t_pipex *pipex, char *format,
				char *error, char *arg);
void		ft_put_error(t_pipex *pipex, char *arg);
void		ft_exit_on_error(t_pipex *pipex, int exit_code);

#endif 