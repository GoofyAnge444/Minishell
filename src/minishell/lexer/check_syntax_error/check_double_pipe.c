/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:44:06 by eazard            #+#    #+#             */
/*   Updated: 2025/02/18 18:07:52 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_a_pipe_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == PIPE_TK)
		return (true);
	return (false);
}

bool	check_double_pipe(t_data *data)
{
	t_dll_node	*node;

	if (data ->non_fatal_error_occured == false)
	{
		node = data -> lexer -> linked_token -> head;
		while (node)
		{
			if (is_a_pipe_token(node)
				&& node -> next && is_a_pipe_token(node -> next))
				return (true);
			node = node -> next;
		}
	}
	return (false);
}
