/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:54:50 by eazard            #+#    #+#             */
/*   Updated: 2025/05/02 13:41:16 by eazard           ###   ########.fr       */
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

static void	fill_infile_fd(t_data *data, t_redir *redir, t_cmd_content *cmd)
{
	if (redir->redir_type == INPUT_TK)
		cmd->fd_in = open(redir->filename, O_RDONLY);
	else if (redir->redir_type == HEREDOC_TK)
		cmd->fd_in = heredoc(data, redir->filename,
				redir -> heredoc__expend_env_var);
}

static void	fill_outfile_fd(t_redir *redir, t_cmd_content *cmd)
{
	if (cmd -> fd_out >= 0)
		close(cmd -> fd_out);
	if (redir->redir_type == TRUNCATE_TK)
		cmd->fd_out
			= open(redir->filename, O_TRUNC | O_CREAT | O_WRONLY,
				BASH_POSIX_CREATED_FILE_WRITE_COPY);
	else if (redir->redir_type == APPEND_TK)
		cmd->fd_out
			= open(redir->filename, O_APPEND | O_CREAT | O_WRONLY,
				BASH_POSIX_CREATED_FILE_WRITE_COPY);
}

void	fill_fd(t_data *data, t_redir **redir_tab, t_cmd_content *cmd)
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
			fill_infile_fd(data, redir_tab[i], cmd);
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
