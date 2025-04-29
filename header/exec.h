/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:25 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 14:03:03 by eazard           ###   ########.fr       */
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
	int								infile_fd;
	int								outfile_fd;
	char							**cmd_args;
	char							*cmd_name;
	bool							skip_cmd;
};

struct								s_exec
{
	t_dll_list						*cmd_dll;
	t_cmd_content					*tmp__cmd_content;
	char							*tmp__heredoc_line;
};

bool			is_builtin(char *cmd);
void			build_cmd_list(t_data *data);
void			exec(t_data *data);
t_cmd_content	*convert_segment_in_cmd(t_data *data,
					t_segment_content *segment);
void			print_cmd_content(t_cmd_content *cmd_content);
void			free_cmd_content(t_cmd_content *cmd_content);
void			fill_fd(t_data *data, t_redir **redir_tab,
					t_cmd_content *cmd);
int				heredoc(t_data *data, char *delimiter);

#endif