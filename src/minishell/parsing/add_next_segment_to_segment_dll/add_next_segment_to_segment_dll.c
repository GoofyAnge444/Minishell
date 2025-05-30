/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_segment_to_segment_dll.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:47:04 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 13:15:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_next_segment_to_segment_dll(t_data *data)
{
	t_segment_content	*segment_content;
	t_dll_node			*segment_node;

	segment_content = ft_calloc(1, sizeof(t_segment_content));
	if (!segment_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	add_cmd_name_to_segment(data, segment_content);
	add_cmd_arg_to_segment(data, segment_content);
	add_redir_tab_to_segment(data, segment_content);
	segment_node = dll_new_node((void *)segment_content);
	if (!segment_node)
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	dll_insert_tail(data -> parsing -> segment_dll, segment_node);
}
