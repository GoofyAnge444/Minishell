/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all_space_tk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:53:07 by eazard            #+#    #+#             */
/*   Updated: 2025/02/18 18:14:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_a_whitespace_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == SPACE_TK)
		return (true);
	return (false);
}

void	delete_all_space_tk(t_data *data)
{
	t_dll_node	*node;

	if (data -> non_fatal_error_occured == false)
	{
		node = data -> lexer -> linked_token -> head;
		if (node)
		{
			while (node && is_a_whitespace_token(node))
			{
				dll_clear_node(node, (void (*)(void *))(&free_token_content));
				node = data -> lexer -> linked_token -> head;
			}
			while (node)
			{
				while (node -> next && is_a_whitespace_token(node -> next))
					dll_clear_node(node -> next,
						(void (*)(void *))(&free_token_content));
				node = node -> next;
			}
		}
	}
}
