/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:21:41 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:23:13 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	set_all_pipe(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node	*cmd;

	cmd = cmd_dll->head;
	while (cmd)
	{
		set_pipe_in_a_cmd(data, cmd);
		cmd = cmd->next;
	}
}
