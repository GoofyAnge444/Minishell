/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_token_of_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:50:13 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:04:54 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_dll_node	*get_first_token_of_command(t_data *data,
				int processed_cmd_index)
{
	int			i;
	t_dll_node	*node;

	i = 1;
	node = data -> lexer -> linked_token -> head;
	while (i < processed_cmd_index)
	{
		while (node && !is_a_pipe_token(node))
			node = node -> next;
		if (is_a_pipe_token(node))
			node = node -> next;
		i++;
	}
	return (node);
}
