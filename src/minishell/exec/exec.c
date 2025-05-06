/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:00:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/06 14:57:08 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	exec_all_command(t_data *data)
{
	t_dll_node	*cmd;
	t_dll_node	*segment;

	segment = data -> parsing -> segment_dll -> head;
	cmd = data -> exec -> cmd_dll -> head;
	while (cmd)
	{
		exec_cmd(data, cmd, segment);
		segment = segment -> next;
		cmd = cmd -> next;
	}
}

static void	wait_cmd(t_data *data, t_dll_node *cmd,
		int *status)
{
	t_cmd_content	*content;

	content = cmd -> content;
	waitpid(content -> pid, status, 0);
	(void)data;
}

static void	update_last_exit_code(int status)
{
	if (WIFEXITED(status))
	{
		g_last_exit_code = WEXITSTATUS(status);
	}
	if (WIFSIGNALED(status))
		g_last_exit_code = 128 + WTERMSIG(status);
}

static void	wait_all_command(t_data *data)
{
	t_dll_node	*cmd;
	int			status;

	cmd = data -> exec -> cmd_dll -> head;
	while (cmd)
	{
		wait_cmd(data, cmd, &status);
		cmd = cmd -> next;
	}
	update_last_exit_code(status);
}

void	exec(t_data *data)
{
	if (data->non_fatal_error_occured == false)
	{
		build_cmd_list(data);
		exec_all_command(data);
		wait_all_command(data);
		// clean data
	}
}