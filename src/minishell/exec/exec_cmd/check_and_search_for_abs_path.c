/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_search_for_abs_path.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:05:46 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 17:11:10 by eazard           ###   ########.fr       */
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
	DIR	*dir;

	if (cmd_name_start_with_relativ_path(content -> cmd_name))
	{
		dir = opendir(content->cmd_name);
		if (dir)
		{
			closedir(dir);
			ft_printf_fd(2, "minishell: %s: Is a directory\n",
				content -> cmd_name);
			fatal_error_clean_exit(data, IS_A_DIRECTORY);
		}
		if (-1 == access(content->cmd_name, F_OK))
		{
			ft_printf("here\n");
			ft_printf_fd(2, "minishell: %s: No such file or directory\n",
				content -> cmd_name);
			fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
		}
	}
	else if (!cmd_name_is_already_in_absolute_format(content -> cmd_name))
		add_absolute_path_to_cmd_name(data, content);
	if (0 != access(content -> cmd_name, X_OK))
		permission_denied_error(data, content -> cmd_name);
}
