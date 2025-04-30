/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:05:54 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 19:01:25 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
/*
requirement :
	- all pipe are set up : TODO
*/
void	exec_cmd(t_data *data , t_dll_node	*cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	content -> pid = fork();
	if (content -> pid == -1)
		fatal_error_clean_exit(data, FORK_FAILURE);
	else if (content -> pid == 0)
		(void)data;// child_process();
	else
		(void)data;// parent_process();
}