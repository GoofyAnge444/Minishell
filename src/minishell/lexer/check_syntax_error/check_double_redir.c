/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:20 by eazard            #+#    #+#             */
/*   Updated: 2025/02/18 18:10:02 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_a_redir_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == APPEND_TK ||
	((t_token_content *)(node -> content))->type == OUTPUT_TK || \
	((t_token_content *)(node -> content))->type == INPUT_TK || \
	((t_token_content *)(node -> content))->type == HEREDOC_TK)
		return (true);
	return (false);
}

bool	check_double_redir(t_data *data)
{
	t_dll_node	*node;

	if (data ->non_fatal_error_occured == false)
	{
		node = data -> lexer -> linked_token -> head;
		while (node)
		{
			if (is_a_redir_token(node)
				&& node -> next && is_a_redir_token(node -> next))
				return (true);
			node = node -> next;
		}
	}
	return (false);
}

