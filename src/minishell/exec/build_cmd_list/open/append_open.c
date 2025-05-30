/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:46:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:47:22 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	append_open(t_redir *redir, t_cmd_content *cmd)
{
	cmd->fd_out
		= open(redir->filename, O_APPEND | O_CREAT | O_WRONLY,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (-1 == cmd->fd_out)
	{
		ft_printf_fd(2, "mishell : ");
		perror(redir->filename);
	}
}
