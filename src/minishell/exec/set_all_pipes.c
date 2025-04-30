/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:21:41 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 18:58:35 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
set_all_pipe - pseudo_code
SI
parcours la liste de command, pour chaque command effectue une pipe si :
cette command n'a aucun fd_out (fd_out vaut alors -2)
OU
la prochaine commande existe ET elle n'a aucun fd_in (fd_in vaut alors -2)
ALORS
	{
	SI cette command n'a aucun fd_out (fd_out vaut alors -2)
		ALORS
			on va dup le pipe[1] vers le fdout;
	close le pipe [1]
	SI la prochaine commande existe ET elle n'a aucun fd_in (fd_in vaut alors -2)
		ALORS
		on va dup le pipe[0] vers le fdin de la prochaine commande;
	close le pipe [0];
	
	}

SINON
	rien;
*/

static inline bool	this_command_has_no_output_set(t_cmd_content *cmd)
{
	return (cmd->fd_out == -2);
}

static inline bool	next_command_has_no_input_set(t_cmd_content *cmd)
{
	return (cmd->fd_in == -2);
}

static void	dup_pipe_out_to_cmd_out_fd(t_data *data, t_cmd_content *cmd,
		int pipe_out)
{
	cmd->fd_out = dup(pipe_out);
	if (-1 == cmd->fd_in)
		fatal_error_clean_exit(data, DUP_FAILURE);
}

static void	dup_pipe_in_to_next_cmd_in_fd(t_data *data, t_cmd_content *cmd,
		int pipe_in)
{
	cmd->fd_in = dup(pipe_in);
	if (-1 == cmd->fd_in)
		fatal_error_clean_exit(data, DUP_FAILURE);
}

void	set_all_pipe(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node	*cmd;
	int			pipe_fd[2];

	cmd = cmd_dll->head;
	while (cmd)
	{
		if (this_command_has_no_output_set(cmd->content) || (cmd->next
				&& next_command_has_no_input_set(cmd->next->content)))
		{
			if (pipe(pipe_fd) == -1)
				fatal_error_clean_exit(data, PIPE_FAILURE);
			if (this_command_has_no_output_set(cmd->content))
				dup_pipe_out_to_cmd_out_fd(data, cmd->content, pipe_fd[1]);
			close(pipe_fd[1]);
			if (cmd->next && next_command_has_no_input_set(cmd->next->content))
				dup_pipe_in_to_next_cmd_in_fd(data, cmd->next->content,
					pipe_fd[0]);
			close(pipe_fd[0]);
		}
		cmd = cmd->next;
	}
}
