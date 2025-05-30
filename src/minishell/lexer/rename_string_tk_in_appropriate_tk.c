/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_string_tk_in_appropriate_tk.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:11:03 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 14:24:01 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	rename_str_to_file_tk(t_data *data)
{
	t_dll_node	*node;

	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		if (is_a_redir_token(node))
			((t_token_content *)(node -> next -> content))-> type = FILE_TK;
		node = node -> next;
	}
}

static bool	there_is_no_cmd_tk_in_actual_command(t_dll_node *node)
{
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_cmd_token(node))
			return (false);
		node = node -> prev;
	}
	return (true);
}

static void	rename_str_to_cmd_tk(t_data *data)
{
	t_dll_node	*node;

	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		while (node && !is_a_pipe_token(node))
		{
			if (is_a_string_token(node)
				&& there_is_no_cmd_tk_in_actual_command(node))
				((t_token_content *)(node -> content))-> type = CMD_TK;
			node = node -> next;
		}
		if (node)
			node = node -> next;
	}
}

static void	rename_str_to_arg_tk(t_data *data)
{
	t_dll_node	*node;

	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		if (is_a_string_token(node))
			((t_token_content *)(node -> content))-> type = ARG_TK;
		node = node -> next;
	}
}

void	rename_string_tk_in_appropriate_tk(t_data *data)
{
	if (data ->non_fatal_error_occured == false)
	{
		rename_str_to_file_tk(data);
		rename_str_to_cmd_tk(data);
		rename_str_to_arg_tk(data);
	}
}
