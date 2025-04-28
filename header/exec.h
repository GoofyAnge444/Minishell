/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:25 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 15:12:39 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "minishell.h"

typedef struct s_exec				t_exec;
typedef struct s_cmd_content		t_cmd_content;
typedef struct s_segment_content	t_segment_content;

struct s_cmd_content
{
	int		infile_fd;
	int		outfile_fd;
	char	**cmd_args;
	char	*cmd_name;
	bool	skip_cmd;
};

struct s_exec
{
	t_dll_list	*cmd_dll;
};

bool			is_builtin(char *cmd);
void			build_cmd_list(t_data *data);
void			exec(t_data *data);
t_cmd_content	*convert_segment_in_cmd(t_segment_content *segment);
void			print_cmd_content(t_cmd_content *cmd_content);
void			free_cmd_content(t_cmd_content *cmd_content);

#endif