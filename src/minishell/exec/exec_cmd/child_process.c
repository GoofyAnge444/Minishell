/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:19 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 16:12:27 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	launch_builtin_then_exit_if_success(t_data *data,
				t_cmd_content *content)
{
	if (-1 == launch_builtin(content, data))
		fatal_error_clean_exit(data, LAUNCH_BUILTIN_FAILURE);
	else
	{
		free_data(data, true);
		exit(0);
	}
}

void	child_process(t_data *data, t_dll_node *cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	if (content -> cmd_name)
	{
		if (content -> fd_in >= 0 && -1 == dup2(content ->fd_in, STDIN_FILENO))
			fatal_error_clean_exit(data, DUP2_FAILURE);
		if (content -> fd_out >= 0 && -1 == dup2(content ->fd_out,
				STDOUT_FILENO))
			fatal_error_clean_exit(data, DUP2_FAILURE);
		close_cmd_fd(cmd, true);
		if (is_builtin(content->cmd_name))
			launch_builtin_then_exit_if_success(data, content);
		else
		{
			if (-1 == launch_non_builtin(content, data))
				fatal_error_clean_exit(data, EXECVE_FAILURE);
		}
	}
}
