/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:46:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:47:19 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	heredoc_open(t_redir *redir, t_cmd_content *cmd)
{
	(void)redir;
	cmd->fd_in = open(".heredoc_tmp", O_RDONLY);
	if (-1 == cmd->fd_in)
		perror("mishell : ");
}
