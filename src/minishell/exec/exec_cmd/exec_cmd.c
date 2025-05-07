/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:05:54 by eazard            #+#    #+#             */
/*   Updated: 2025/05/07 16:59:25 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	launch_non_builtin(t_data *data, t_dll_node *cmd,
				t_cmd_content *cmd_content)
{
	cmd_content -> pid = fork();
	if (cmd_content -> pid == -1)
		fatal_error_clean_exit(data, FORK_FAILURE);
	else if (cmd_content -> pid == 0)
		child_process(data, cmd);
	else
		parent_process(data, cmd);
}

void	exec_cmd(t_data *data, t_dll_node *cmd, t_dll_node *segment)
{
	t_cmd_content		*cmd_content;
	t_segment_content	*segment_content;

	cmd_content = cmd -> content;
	segment_content = segment -> content;
	fill_fd(data, segment_content->redir_tab, cmd -> content);
	set_pipe_in_a_cmd(data, cmd);
	if (!data -> exec -> envp)
		convert_env_dll_into_env_str_tab(data);
	if (cmd_content -> cmd_name)
	{
		if (is_builtin(cmd_content -> cmd_name) == true)
			ft_printf("builtin\n");//launc_builtin
		else
			launch_non_builtin(data, cmd, cmd_content);
	}
	else
		close_cmd_fd(cmd, false);
}
