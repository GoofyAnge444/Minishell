/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:00:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 18:03:56 by eazard           ###   ########.fr       */
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
		if (((t_cmd_content *)cmd -> content)->skip_cmd == false)
			exec_cmd(data, cmd, segment);
		segment = segment -> next;
		cmd = cmd -> next;
	}
}

static pid_t	wait_cmd(t_data *data, t_dll_node *cmd,
		int *status)
{
	t_cmd_content	*content;

	(void)data;
	content = cmd -> content;
	return (waitpid(content -> pid, status, 0));
}

static void	update_last_exit_code(t_data *data, int status)
{
	if (WIFEXITED(status))
	// {
		data -> last_exit_code = WEXITSTATUS(status);
		// ft_printf("WEXITSTATUS = %i\n", WEXITSTATUS(status));
	// }
	else if (WIFSIGNALED(status))
	// {
		data -> last_exit_code = 128 + WTERMSIG(status);
		// ft_printf("WTERMSIG = %i\n", WTERMSIG(status));
	// }
}

static void	wait_all_command(t_data *data)
{
	t_dll_node		*cmd;
	int				status;
	pid_t			waited_pid;
	t_cmd_content	*content;

	cmd = data -> exec -> cmd_dll -> head;
	while (cmd)
	{
		content = cmd -> content;
		if (content->cmd_name && content -> exec_cmd_in_parent_process == false
			&& content ->skip_cmd == false)
		{
			waited_pid = wait_cmd(data, cmd, &status);
			while (-1 == waited_pid && errno == EINTR)
			// {
				// ft_printf("wainting_pid...\n");
				waited_pid = wait_cmd(data, cmd, &status);
			update_last_exit_code(data, status);
			// }
		}
		cmd = cmd -> next;
		// if (waited_pid
		// 	== ((t_cmd_content *)data->exec->cmd_dll->tail->content)->pid)
	}
	 //if smt TODO

	// if (false == updated)
	// {
	// 	ft_printf("waited pid = %i\n", waited_pid);
	// 	data -> last_exit_code = 1;
	// 	printf("forcing update_last_exit_code to 1\n");
	// }
}

void	exec(t_data *data)
{
	if (data->non_fatal_error_occured == false)
	{
		build_cmd_list(data);
		if (data -> non_fatal_error_occured == true)
			return ;
		exec_all_command(data);
		wait_all_command(data);
		// clean data
	}
}
