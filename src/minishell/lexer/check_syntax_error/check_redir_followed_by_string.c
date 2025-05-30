/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_followed_by_string.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:35:20 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:51:36 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	check_redir_followed_by_string(t_data *data)
{
	t_dll_node	*node;

	if (data ->non_fatal_error_occured == false)
	{
		node = data -> lexer -> linked_token -> head;
		while (node)
		{
			if (is_a_redir_token(node)
				&& (!node -> next \
				|| (node -> next && !is_a_string_token(node -> next))))
				return (true);
			node = node -> next;
		}
	}
	return (false);
}
