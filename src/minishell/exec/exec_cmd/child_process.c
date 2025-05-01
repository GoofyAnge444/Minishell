/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:41:19 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 15:35:56 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static inline bool	cmd_name_is_already_in_absolute_format(char *cmd_name)
{
	return (cmd_name[0] == '/');
}

static void	close_child_files(t_cmd_content *content)
{
	if (content -> fd_in >= 0)
		close(content -> fd_in);
	if (content -> fd_out >= 0)
		close(content -> fd_out);
}


void	child_process(t_data *data, t_dll_node *cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	if (content -> cmd_name)
	{
		// ft_printf("conent -> fd_in = %i\n", content -> fd_in);
		if (content -> fd_in >= 0 && -1 == dup2(content ->fd_in, STDIN_FILENO))
			fatal_error_clean_exit(data, DUP2_FAILURE);
		if (content -> fd_out >= 0 && -1 == dup2(content ->fd_out, STDOUT_FILENO))
			fatal_error_clean_exit(data, DUP2_FAILURE);
		
		close_child_files(content);
		if (!data -> exec -> envp)
			convert_env_dll_into_env_str_tab(data);
		if (!cmd_name_is_already_in_absolute_format(content -> cmd_name))
			add_absolute_path_to_cmd_name(data, content);
		if (-1 == execve(content -> cmd_name, content -> cmd_args,
				data -> exec -> envp))
			fatal_error_clean_exit(data, EXECVE_FAILURE);
	}
}
