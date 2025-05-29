/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:54:50 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 17:54:12 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static inline bool	is_a_infile_redir(t_redir *redir)
{
	return (redir->redir_type == INPUT_TK || redir->redir_type == HEREDOC_TK);
}

static inline void	set_command_to_be_skiped_in_exec(t_cmd_content *cmd)
{
	cmd->skip_cmd = true;
}

static void	fill_infile_fd(t_redir *redir, t_cmd_content *cmd)
{
	if (redir->redir_type == INPUT_TK)
	{
		infile_open(redir, cmd);
	}
	else if (redir->redir_type == HEREDOC_TK)
	{
		heredoc_open(redir, cmd);
	}
}

static void	fill_outfile_fd(t_redir *redir, t_cmd_content *cmd)
{
	if (cmd -> fd_out >= 0)
		close(cmd -> fd_out);
	if (redir->redir_type == TRUNCATE_TK)
	{
		if (-1 == access(redir->filename, W_OK))
		{
			ft_printf("mishell : ");
			perror(redir->filename);
		}
		cmd->fd_out
			= open(redir->filename, O_TRUNC | O_CREAT | O_WRONLY,
				BASH_POSIX_CREATED_FILE_WRITE_COPY);
		if (!cmd->fd_out)
			perror("mishell : ");
	}
	else if (redir->redir_type == APPEND_TK)
		append_open(redir, cmd);
}

void	fill_fd(t_redir **redir_tab, t_cmd_content *cmd)
{
	size_t	i;

	i = 0;
	while (redir_tab && redir_tab[i])
	{
		if (is_a_infile_redir(redir_tab[i]))
		{
			if (cmd -> fd_in > 0)
				close(cmd -> fd_in);
			cmd -> fd_in = -2;
			fill_infile_fd(redir_tab[i], cmd);
			if (cmd->fd_in == -1)
				return (set_command_to_be_skiped_in_exec(cmd));
		}
		else
		{
			if (cmd -> fd_out > 0)
				close(cmd -> fd_out);
			cmd -> fd_out = -2;
			fill_outfile_fd(redir_tab[i], cmd);
			if (cmd->fd_out == -1)
				return (set_command_to_be_skiped_in_exec(cmd));
		}
		i++;
	}
}
