/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:00:08 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 19:00:28 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// static void	exec_all_command(t_data *data)
// {
// 	t_dll_node	*cmd;

// 	cmd = data -> exec -> cmd_dll -> head;
// 	while (cmd)
// 	{
// 		exec_cmd(data, cmd);
// 		cmd = cmd -> next;
// 	}
// }

// static void	wait_all_command(t_data *data)
// {
// 	t_dll_node	*cmd;

// 	cmd = data -> exec -> cmd_dll -> head;
// 	while (cmd)
// 	{
// 		wait_cmd(data, cmd);
// 		cmd = cmd -> next;
// 	}
// }

void	exec(t_data *data)
{
	if (data->non_fatal_error_occured == false)
	{
		build_cmd_list(data);
		// exec_all_command(data);
		// wait_all_command(data);
		// clean data
	}
}