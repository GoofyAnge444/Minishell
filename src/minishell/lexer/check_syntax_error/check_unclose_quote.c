/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclose_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:37 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:33:59 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_unclose_quote(t_dll_node *node)
{
	char	*value;

	value = ((t_token_content *)(node -> content))->value;
	if (value[0] != value[ft_strlen(value) - 1])
		return (true);
	return (false);
}

static t_dll_node	*get_last_quote_node(t_data *data)
{
	t_dll_node	*node;

	node = data -> lexer -> linked_token -> head;
	if (!node)
		return (NULL);
	while (node -> next)
		node = node -> next;
	if (is_a_quote_token(node))
		return (node);
	return (NULL);
}

bool	check_unclose_quote(t_data *data)
{
	t_dll_node	*node;

	if (data ->non_fatal_error_occured == false)
	{
		node = get_last_quote_node(data);
		if (!node)
			return (false);
		if (is_unclose_quote(node))
			return (true);
	}
	return (false);
}
