/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:25 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 17:55:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "minishell.h"
# define BASH_POSIX_CREATED_FILE_WRITE_COPY 0644

typedef struct s_exec				t_exec;
typedef struct s_cmd_content		t_cmd_content;
typedef struct s_segment_content	t_segment_content;
typedef struct s_redir				t_redir;
typedef struct s_env_content		t_env_content;

struct								s_cmd_content
{
	int								fd_in;
	int								fd_out;
	char							**cmd_args;
	char							*cmd_name;
	bool							skip_cmd;
	bool							exec_cmd_in_parent_process;
	pid_t							pid;
};

struct								s_exec
{
	t_dll_list						*cmd_dll;
	t_cmd_content					*tmp__cmd_content;
	char							*tmp__heredoc_line;
	char							**envp;
	char							**bin_paths;
	int								pipe[2];
};

/* utils */
void			free_cmd_content(t_cmd_content *cmd_content);
void			print_cmd_content(t_cmd_content *cmd_content);

/* open */
void			infile_open(t_redir *redir, t_cmd_content *cmd);
void			heredoc_open(t_redir *redir, t_cmd_content *cmd);
void			append_open(t_redir *redir, t_cmd_content *cmd);
void			truncate_open(t_redir *redir, t_cmd_content *cmd);


/* build_cmd_list */
void			build_cmd_list(t_data *data);
bool			is_builtin(char *cmd);
void			exec(t_data *data);
t_cmd_content	*convert_segment_in_cmd(t_data *data,
					t_segment_content *segment);
void			fill_fd(t_redir **redir_tab,
					t_cmd_content *cmd);
void			set_all_pipe(t_data *data, t_dll_list *cmd_dll);
void			set_pipe_in_a_cmd(t_data *data, t_dll_node *cmd);
int				heredoc(t_data *data, char *delimiter, bool expend_env_var);

/* exec_cmd */
void			exec_cmd(t_data *data, t_dll_node	*cmd, t_dll_node *segment);
char			*ft_strjoin_with_separator(char const *prefix,
					char const *suffix, char separtor);
void			child_process(t_data *data, t_dll_node *cmd);
void			convert_env_dll_into_env_str_tab(t_data *data);
void			add_absolute_path_to_cmd_name(t_data *data,
					t_cmd_content *content);
void			parent_process(t_data	*data, t_dll_node *cmd);
void			close_cmd_fd(t_dll_node *cmd, bool close_next_cmd);
int				launch_non_builtin(t_cmd_content *content, t_data *data);
int				launch_builtin(t_cmd_content *content, t_data *data);
void			check_and_search_for_abs_path(t_data *data, t_cmd_content *content);

/*builtins*/
void			set_last_exit_code(t_data *data, int last_exit_code);
void			set_var_in_list(t_dll_list *list, char *name,
					char *value, t_data *data);
// void			ft_set_env(t_env_content *tmp_env, t_data *data);
// void			ft_set_env_var(const char *name, const char *value, t_data *data);
char			*ft_getenv(char *name, t_data *data);
void			ft_echo(t_cmd_content *content);
void			ft_exit(t_cmd_content *content, t_data *data);
void			ft_pwd(void);
void			ft_env(t_data *data);
void			ft_cd(t_cmd_content *content, t_data *data);
void			ft_export(t_cmd_content *content, t_data *data);
void			ft_unset(t_cmd_content *content, t_data *data);
void			set_builtin_cmd_to_be_exec_in_parent_process(t_data *data,
					t_dll_list *cmd_dll);
void			set_builtin_cmd_to_skip(t_data *data, t_dll_list *cmd_dll);
void			freeing_experience(t_env_content *tmp_env, t_data *data);
#endif