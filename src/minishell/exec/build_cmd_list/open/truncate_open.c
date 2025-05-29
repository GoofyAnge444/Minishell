/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:46:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 18:06:45 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	truncate_open(t_redir *redir, t_cmd_content *cmd)
{
	// if (-1 == access(redir->filename, W_OK))
	// {
	// 	ft_printf_fd(2, "mishell : ");
	// 	perror(redir->filename);
	// }
	cmd->fd_out
		= open(redir->filename, O_TRUNC | O_CREAT | O_WRONLY,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (-1 == cmd->fd_out)
	{
		ft_printf_fd(2, "mishell : ");
		perror(redir->filename);
	}
}
