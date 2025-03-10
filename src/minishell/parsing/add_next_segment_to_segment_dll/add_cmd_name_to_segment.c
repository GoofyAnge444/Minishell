/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_name_to_segment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:35:00 by eazard            #+#    #+#             */
/*   Updated: 2025/03/10 11:58:00 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_cmd_name_to_segment(t_data *data,
			t_segment_content *segment_content)
{
	t_dll_node	*node;

	node = get_first_token_of_segment(data);
	while (node && !is_a_pipe_token(node) &&!is_a_cmd_token(node))
		node = node -> next;
	if (node && is_a_cmd_token(node))
	{
		(segment_content -> cmd_name) = ft_strdup(get_token_value(node));
		if (!segment_content -> cmd_name)
			return (free_segment_content(segment_content),
				fatal_error_clean_exit(data, MALLOC_FAILURE));
	}
	else
		segment_content -> cmd_name = NULL;
}
