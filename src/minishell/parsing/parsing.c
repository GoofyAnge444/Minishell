/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:42 by eazard            #+#    #+#             */
/*   Updated: 2025/03/08 19:28:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_segment(t_data *data)
{
	t_dll_node	*node;
	int			segment_count;

	segment_count = 0;
	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		if (is_a_pipe_token(node))
			segment_count++;
		node = node -> next;
	}
	return (segment_count + 1);
}

static void	fill_segment_dll(t_data *data)
{
	while (data -> parsing -> segment_processed
		< data -> parsing -> segment_count)
	{
		add_next_segment_to_segment_dll(data);
		data -> parsing -> segment_processed++;
	}
}

void	parsing(t_data *data)
{
	if (data -> non_fatal_error_occured == false)
	{
		create_segment_dll(data);
		data -> parsing -> segment_count = count_segment(data);
		ft_printf("segment_count = %i\n", data -> parsing -> segment_count); // a retirer
		data -> parsing -> segment_processed = 0;
		fill_segment_dll(data);
	}
}
