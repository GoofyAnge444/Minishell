/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_throught_cmd_dll_and_process_heredoc.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:16:35 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 15:54:35 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	exec_heredoc_in_these_cmd(t_data *data, t_cmd_content *cmd,
				t_segment_content *segment)
{
	size_t	i;

	i = 0;
	while (false == data -> non_fatal_error_occured
		&& segment->redir_tab && segment->redir_tab[i])
	{
		if (HEREDOC_TK == segment->redir_tab[i]->redir_type)
		{
			if (-1 == heredoc(data, segment->redir_tab[i]->filename,
					segment->redir_tab[i]->heredoc__expend_env_var))
				cmd -> skip_cmd = true;
			if (data -> non_fatal_error_occured)
				return ;
		}
		i++;
	}
}

void	go_throught_cmd_dll_and_process_heredoc(t_data *data)
{
	t_dll_node	*cmd;
	t_dll_node	*segment;

	if (data -> exec -> cmd_dll && data -> parsing -> segment_dll)
	{
		cmd = data -> exec -> cmd_dll -> head;
		segment = data -> parsing -> segment_dll -> head;
		while (data -> non_fatal_error_occured == false && cmd)
		{
			exec_heredoc_in_these_cmd(data, cmd->content, segment->content);
			if (data -> non_fatal_error_occured)
				return ;
			cmd = cmd -> next;
			segment = segment -> next;
		}
	}
	else
		ft_printf_fd(2,
			"data -> exec -> cmd_dll && data -> parsing -> segment_dll FALSE\n");
}
