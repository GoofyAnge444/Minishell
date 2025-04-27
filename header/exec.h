/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:25 by eazard            #+#    #+#             */
/*   Updated: 2025/04/27 18:24:07 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "minishell.h"

typedef struct s_exec			t_exec;
typedef struct s_cmd_content	t_cmd_content;

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

#endif