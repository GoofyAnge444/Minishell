/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:00:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 14:54:39 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	exec_all_command(t_data *data)
{
	t_dll_node	*cmd;

	cmd = data -> exec -> cmd_dll -> head;
	while (cmd)
	{
		exec_cmd(data, cmd);
		cmd = cmd -> next;
	}
}

static void	wait_cmd(t_data *data, t_dll_node *cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	waitpid(content -> pid, NULL, 0);
	(void)data;
}

static void	wait_all_command(t_data *data)
{
	t_dll_node	*cmd;

	cmd = data -> exec -> cmd_dll -> head;
	while (cmd)
	{
		wait_cmd(data, cmd);
		cmd = cmd -> next;
	}
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