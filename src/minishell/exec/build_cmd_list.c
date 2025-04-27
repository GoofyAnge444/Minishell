/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:43:54 by eazard            #+#    #+#             */
/*   Updated: 2025/04/27 18:41:44 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	create_cmd_list(t_data *data)
{
	data -> exec -> cmd_dll = dll_new_list();
	if (! data -> exec -> cmd_dll)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}

static void	fill_cmd_list(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node		*parsing_segment;
	t_dll_node		*new_cmd_dll_node;
	
	parsing_segment = data -> parsing -> segment_dll -> head;
	while (parsing_segment)
	{
		ft_printf("converting one segment...\n");
		new_cmd_dll_node = convert_parsing_segment_in_cmd_node(parsing_segment);
		if (!new_cmd_dll_node)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		dll_insert_tail(cmd_dll, new_cmd_dll_node);
		parsing_segment = parsing_segment -> next;
	}
}

void	build_cmd_list(t_data *data)
{
	create_cmd_list(data);
	fill_cmd_list(data, data -> exec -> cmd_dll);
}