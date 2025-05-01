/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:25 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 14:33:15 by eazard           ###   ########.fr       */
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

struct								s_cmd_content
{
	int								fd_in;
	int								fd_out;
	char							**cmd_args;
	char							*cmd_name;
	bool							skip_cmd;
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

/* build_cmd_list */
void			build_cmd_list(t_data *data);
bool			is_builtin(char *cmd);
void			exec(t_data *data);
t_cmd_content	*convert_segment_in_cmd(t_data *data,
					t_segment_content *segment);
void			fill_fd(t_data *data, t_redir **redir_tab,
					t_cmd_content *cmd);
void			set_all_pipe(t_data *data, t_dll_list *cmd_dll);
int				heredoc(t_data *data, char *delimiter, bool expend_env_var);

/* exec_cmd */
void			exec_cmd(t_data *data, t_dll_node	*cmd);
char			*ft_strjoin_with_separator(char const *prefix,
					char const *suffix, char separtor);
void			child_process(t_data *data, t_dll_node *cmd);
void			convert_env_dll_into_env_str_tab(t_data *data);
void			add_absolute_path_to_cmd_name(t_data *data,
					t_cmd_content *content);
void			parent_process(t_data	*data, t_dll_node *cmd);

#endif