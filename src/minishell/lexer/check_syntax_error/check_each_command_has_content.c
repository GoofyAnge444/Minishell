/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_each_command_has_content.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:44:06 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 17:42:15 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	check_each_command_has_content(t_data *data)
{
	t_dll_node	*node;

	if (data ->non_fatal_error_occured == false)
	{
		node = data -> lexer -> linked_token -> head;
		while (node)
		{
			if (is_a_pipe_token(node) \
			&& ((node -> next && is_a_pipe_token(node -> next)) \
			|| !(node -> next)))
				return (true);
			node = node -> next;
		}
	}
	return (false);
}
