/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_token_of_segment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:50:13 by eazard            #+#    #+#             */
/*   Updated: 2025/03/08 19:13:06 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_dll_node	*get_first_token_of_segment(t_data *data)
{
	int			i;
	t_dll_node	*node;

	i = 0;
	node = data -> lexer -> linked_token -> head;
	while (i < data -> parsing -> segment_processed)
	{
		while (node && !is_a_pipe_token(node))
			node = node -> next;
		if (is_a_pipe_token(node))
			node = node -> next;
		i++;
	}
	return (node);
}
