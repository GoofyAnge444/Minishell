/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:43:54 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 18:24:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_dll_node	*get_next_cmd_node(t_data *data, t_dll_node *segment_node)
{
	t_cmd_content		*cmd_content;
	t_dll_node			*next_cmd_node;

	cmd_content
		= convert_segment_in_cmd(data,
			(t_segment_content *)segment_node ->content);
	if (!cmd_content)
		return (NULL);
	next_cmd_node = dll_new_node((void *)cmd_content);
	if (!next_cmd_node)
		return (free_cmd_content(cmd_content), NULL);
	return (next_cmd_node);
}

static void	create_cmd_list(t_data *data)
{
	data -> exec -> cmd_dll = dll_new_list();
	if (! data -> exec -> cmd_dll)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}

static void	fill_cmd_list_with_parsed_data(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node		*parsing_segment;
	t_dll_node		*next_cmd_node;

	parsing_segment = data -> parsing -> segment_dll -> head;
	while (parsing_segment)
	{
		next_cmd_node = get_next_cmd_node(data, parsing_segment);
		if (!next_cmd_node)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		dll_insert_tail(cmd_dll, next_cmd_node);
		parsing_segment = parsing_segment -> next;
	}
}



void	build_cmd_list(t_data *data)
{
	create_cmd_list(data);
	fill_cmd_list_with_parsed_data(data, data -> exec -> cmd_dll);
	set_all_pipe(data, data -> exec -> cmd_dll);
}
