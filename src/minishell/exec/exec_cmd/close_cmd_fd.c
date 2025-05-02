/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_cmd_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:31:48 by eazard            #+#    #+#             */
/*   Updated: 2025/05/02 13:34:12 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_cmd_fd(t_dll_node *cmd, bool close_next_cmd)
{
	t_cmd_content	*content;

	content = cmd -> content;
	if (content -> fd_in >= 0)
		close(content -> fd_in);
	if (content -> fd_out >= 0)
		close(content -> fd_out);
	if (close_next_cmd && cmd -> next)
		close_cmd_fd(cmd->next, false);
}
