/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:23:46 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 15:36:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	close_parent_files(t_cmd_content *content)
{
	if (content -> fd_in >= 0)
		close(content -> fd_in);
	if (content -> fd_out >= 0)
		close(content -> fd_out);
}

void	parent_process(t_data	*data, t_dll_node *cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	close_parent_files(content);
	(void)data;
}
