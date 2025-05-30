/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_arg_to_segment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:37:04 by eazard            #+#    #+#             */
/*   Updated: 2025/03/10 12:00:01 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	bool	there_is_cmd_tk_in_this_cmd(t_dll_node *first_node_of_cmd)
{
	t_dll_node	*node;

	node = first_node_of_cmd;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_cmd_token(node))
			return (true);
		node = node -> next;
	}
	return (false);
}

static void	add_cmd_name_in_arg_tab(t_data *data,
				t_segment_content *segment_content)
{
	(segment_content -> cmd_args)[0] = ft_strdup(segment_content -> cmd_name);
	if (!(segment_content -> cmd_args)[0])
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

static void	add_arg_in_arg_tab(t_data *data, t_segment_content *segment_content,
				t_dll_node *first_token_of_segment)
{
	t_dll_node	*node;
	int			i;

	node = first_token_of_segment;
	i = 1;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_arg_token(node))
		{
			(segment_content -> cmd_args)[i] = ft_strdup(get_token_value(node));
			if (!(segment_content -> cmd_args)[0])
				return (free_segment_content(segment_content),
					fatal_error_clean_exit(data, MALLOC_FAILURE));
			i++;
		}
		node = node -> next;
	}
	(segment_content -> cmd_args)[i] = NULL;
}

static void	allocate_arg_tab_space(t_data *data,
		t_segment_content *segment_content, t_dll_node *first_token_of_segment)
{
	segment_content -> cmd_args
		= ft_calloc(count_cmd_arg_nb_in_this_segment(first_token_of_segment) \
			+ 2, \
		sizeof(char *));
	if (!segment_content -> cmd_args)
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

void	add_cmd_arg_to_segment(t_data *data,
			t_segment_content *segment_content)
{
	t_dll_node	*first_token_of_segment;

	first_token_of_segment = get_first_token_of_segment(data);
	if (there_is_cmd_tk_in_this_cmd(first_token_of_segment))
	{
		allocate_arg_tab_space(data, segment_content, first_token_of_segment);
		add_cmd_name_in_arg_tab(data, segment_content);
		add_arg_in_arg_tab(data, segment_content, first_token_of_segment);
	}
	else
		segment_content -> cmd_args = NULL;
}
