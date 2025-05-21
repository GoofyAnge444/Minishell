/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:19 by eazard            #+#    #+#             */
/*   Updated: 2025/05/21 18:17:36 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static inline bool	cmd_name_is_already_in_absolute_format(char *cmd_name)
{
	return (cmd_name[0] == '/');
}

static inline bool	cmd_name_start_with_relativ_path(char *cmd_name)
{
	return ((cmd_name[0] == '.' && cmd_name[1] && cmd_name[1] == '/')
		|| (cmd_name[0] == '.' && cmd_name[1] && cmd_name[1] == '.'
			&& cmd_name[2] && cmd_name[2] == '/'));
}

static void	permission_denied_error(t_data *data, char *cmd_name)
{
	ft_printf_fd(2, "minishell: %s: Permission denied\n",
		cmd_name);
	fatal_error_clean_exit(data, NO_EXEC_PERMISSION);
}

void	check_and_search_for_abs_path(t_data *data, t_cmd_content *content)
{
	struct stat	path_stat;

	if (cmd_name_start_with_relativ_path(content -> cmd_name))
	{
		if (0 != stat(content -> cmd_name, &path_stat))
		{
			ft_printf_fd(2, "minishell: %s: No such file or directory\n",
				content -> cmd_name);
			fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
		}
		if (S_ISDIR(path_stat.st_mode))
		{
			ft_printf_fd(2, "minishell: %s: Is a directory\n",
				content -> cmd_name);
			fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
		}
	}
	else if (!cmd_name_is_already_in_absolute_format(content -> cmd_name))
		add_absolute_path_to_cmd_name(data, content);
	if (0 != access(content -> cmd_name, X_OK))
		permission_denied_error(data, content -> cmd_name);
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
		{
			if (-1 == launch_builtin(content, data))
				fatal_error_clean_exit(data, LAUNCH_BUILTIN_FAILURE);
		}
		else
		{
			if (-1 == launch_non_builtin(content, data))
				fatal_error_clean_exit(data, EXECVE_FAILURE);
		}
	}
}
