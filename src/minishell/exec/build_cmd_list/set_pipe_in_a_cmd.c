/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe_in_a_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:25:15 by eazard            #+#    #+#             */
/*   Updated: 2025/05/02 13:25:38 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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

void	set_pipe_in_a_cmd(t_data *data, t_dll_node *cmd)
{
	int			pipe_fd[2];

	if ((this_command_has_no_output_set(cmd->content) && cmd -> next)
		|| (cmd->next
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
}