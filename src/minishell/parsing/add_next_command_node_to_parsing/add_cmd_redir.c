/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:52:10 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 17:47:37 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	bool	there_is_redir_tk_in_this_cmd(t_dll_node *first_node_of_cmd)
{
	t_dll_node	*node;

	node = first_node_of_cmd;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_redir_token(node))
			return (true);
		node = node -> next;
	}
	return (false);
}

static void	fill_redir_content(t_data *data, t_command_content *command_content,
	t_dll_node *node, int i)
{
	((command_content->redir)[i])-> filename
		= ft_strdup(get_token_value(node -> next));
	if (!((command_content->redir)[i])-> filename)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	((command_content->redir)[i])-> redir_type
		= (int)(((t_token_content *)(node ->content))->type);
}

static void	add_all_redir_in_redir_ptr_tab(t_data *data,
	t_command_content *command_content, t_dll_node *first_token_of_cmd)
{
	t_dll_node	*node;
	int			i;

	node = first_token_of_cmd;
	i = 0;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_redir_token(node))
		{
			(command_content->redir)[i] = ft_calloc(1, sizeof(t_redir));
			if (!(command_content->redir)[i])
				return (free_command_content(command_content),
					fatal_error_clean_exit(data, MALLOC_FAILURE));
			fill_redir_content(data, command_content, node, i);
			i++;
		}
		node = node -> next;
	}
	(command_content -> redir)[i] = NULL;
}

static void	allocate_redir_ptr_tab_space(t_data *data,
		t_command_content *command_content, t_dll_node *first_token_of_cmd)
{
	command_content -> redir
		= ft_calloc(count_redir_nb_in_this_command(first_token_of_cmd) + 1, \
		sizeof(t_redir *));
	if (!command_content -> redir)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

void	add_cmd_redir(t_data *data,
	t_command_content *command_content, int processed_cmd_index)
{
	t_dll_node	*first_token_of_cmd;

	first_token_of_cmd = get_first_token_of_command(data, processed_cmd_index);
	if (there_is_redir_tk_in_this_cmd(first_token_of_cmd))
	{
		allocate_redir_ptr_tab_space(data, command_content, first_token_of_cmd);
		add_all_redir_in_redir_ptr_tab(data, command_content,
			first_token_of_cmd);
	}
	else
		command_content -> redir = NULL;
}
