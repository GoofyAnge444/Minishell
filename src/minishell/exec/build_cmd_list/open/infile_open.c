/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:46:08 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 18:06:16 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	infile_open(t_redir *redir, t_cmd_content *cmd)
{
	// if (-1 == access(redir->filename, F_OK | R_OK))
	// {
	// 	ft_printf_fd(2, "mishell : ");
	// 	perror(redir->filename);
	// }
	cmd->fd_in = open(redir->filename, O_RDONLY);
	if (-1 == cmd->fd_in)
	{
		ft_printf_fd(2, "mishell : ");
		perror(redir->filename);
	}
}
