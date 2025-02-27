/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_str_dq_sq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:52:06 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 10:56:08 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_mergeable_type(t_dll_node *node)
{
	t_token_type	type;

	if (node)
	{
		type = ((t_token_content *)(node -> content))-> type;
		if (type == STRING_TK || type == DQ_TK || type == SQ_TK)
			return (true);
	}
	return (false);
}

static void	merge_node_and_its_next(t_data *data, t_dll_node *node)
{
	t_token_content	merged_content;

	merged_content.type = STRING_TK;
	merged_content.value
		= ft_strjoin_dq_sq(((t_token_content *)(node ->content))-> value,
			((t_token_content *)(node -> next ->content))-> value,
			((t_token_content *)(node ->content))-> type,
			((t_token_content *)(node -> next ->content))-> type);
	if (!merged_content.value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	dll_clear_node(node -> next, (void (*)(void *))(&free_token_content));
	free(((t_token_content *)(node -> content))->value);
	*((t_token_content *)(node -> content)) = merged_content;
}

void	merge_str_dq_sq(t_data *data)
{
	t_dll_node	*tmp_node;

	if (data->non_fatal_error_occured == false)
	{
		tmp_node = data -> lexer -> linked_token -> head;
		while (tmp_node)
		{
			while (is_mergeable_type(tmp_node)
				&& is_mergeable_type(tmp_node -> next))
				merge_node_and_its_next(data, tmp_node);
			tmp_node = tmp_node -> next;
		}
	}
}
