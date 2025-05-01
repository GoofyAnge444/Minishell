/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:33:49 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 18:59:34 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_cmd_content(t_cmd_content *cmd_content)
{
	if (cmd_content)
	{
		if (cmd_content -> cmd_args)
			ft_free_tab(cmd_content ->cmd_args);
		if (cmd_content -> cmd_name)
			free(cmd_content -> cmd_name);
		if (cmd_content -> fd_in >= 0)
			close(cmd_content -> fd_in);
		if (cmd_content -> fd_out >= 0)
			close(cmd_content -> fd_out);
		free(cmd_content);
	}
}
