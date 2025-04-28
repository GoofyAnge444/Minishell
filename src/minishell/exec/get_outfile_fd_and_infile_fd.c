/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfile_fd_and_infile_fd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:54:50 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 16:47:00 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	get_outfile_fd_and_infile_fd(t_segment_content *segment,
		t_cmd_content *cmd)
{
	size_t	i;

	i = 0;
	while (segment->redir_tab[i])
	{
		if (segment->redir_tab[i]->redir_type == INPUT_TK)
			cmd->infile_fd = open(segment->redir_tab[i]->filename, O_RDONLY);
		if (segment->redir_tab[i]->redir_type == HEREDOC_TK)
			cmd->infile_fd = heredoc();
		if (segment->redir_tab[i]->redir_type == APPEND_TK)
			cmd->outfile_fd = open(segment->redir_tab[i]->filename,
					O_WRONLY | O_CREAT | O_APPEND);
		if (segment->redir_tab[i]->redir_type == TRUNCATE_TK)
			cmd->outfile_fd = open(segment->redir_tab[i]->filename,
					O_WRONLY | O_CREAT | O_TRUNC);
		if (cmd->outfile_fd == -1 || cmd->infile_fd == -1)
		{
			cmd->skip_cmd = true;
			return ;
		}
		i++;
	}
}
