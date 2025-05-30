/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:05:54 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:50:56 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	launch_builtin_in_parent_process(t_data *data, t_dll_node *cmd)
{
	if (launch_builtin(cmd->content, data) == -1)
		fatal_error_clean_exit(data, LAUNCH_BUILTIN_FAILURE);
	else
		close_cmd_fd(cmd, false);
}

static void	fork_and_redirect_process_in_its_routine(t_data *data,
				t_dll_node *cmd)
{
	t_cmd_content	*cmd_content;

	cmd_content = cmd -> content;
	cmd_content -> pid = fork();
	if (cmd_content -> pid == -1)
		fatal_error_clean_exit(data, FORK_FAILURE);
	else if (cmd_content -> pid == 0)
		child_process(data, cmd);
	else
		parent_process(data, cmd);
}

static void	no_launching_command_routine(t_data *data, t_dll_node *cmd)
{
	t_cmd_content	*cmd_content;

	cmd_content = cmd -> content;
	if (cmd_content ->fd_in == -1 || cmd_content->fd_out == -1)
		data -> last_exit_code = 1;
	else
		data -> last_exit_code = 0;
	close_cmd_fd(cmd, false);
}

void	exec_cmd(t_data *data, t_dll_node *cmd, t_dll_node *segment)
{
	t_cmd_content		*cmd_content;
	t_segment_content	*segment_content;

	cmd_content = cmd -> content;
	segment_content = segment -> content;
	fill_fd(segment_content->redir_tab, cmd -> content);
	if (data -> non_fatal_error_occured == true)
		return ;
	set_pipe_in_a_cmd(data, cmd);
	if (is_builtin(cmd_content ->cmd_name)
		&& cmd_content->exec_cmd_in_parent_process == true)
		return (launch_builtin_in_parent_process(data, cmd));
	if (!data -> exec -> envp)
		convert_env_dll_into_env_str_tab(data);
	if (cmd_content -> cmd_name && cmd_content -> skip_cmd == false)
		fork_and_redirect_process_in_its_routine(data, cmd);
	else
		no_launching_command_routine(data, cmd);
}
