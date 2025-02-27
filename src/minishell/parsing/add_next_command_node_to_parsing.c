/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_command_node_to_parsing.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:42:16 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:20:49 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"



static void	add_cmd_name(t_data *data, t_command_content *command_content,
		int processed_cmd_index)
{
	t_dll_node	*node;

	node = get_first_token_of_command(data, processed_cmd_index);
	while (node && !is_a_pipe_token(node) &&!is_a_cmd_token(node))
		node = node -> next;
	if (node && is_a_cmd_token(node))
	{
		command_content->name = ft_strdup(get_token_value(node));
		if (!command_content ->name)
			return (free_command_content(command_content),
				fatal_error_clean_exit(data, MALLOC_FAILURE));
	}
}

static size_t	count_arg_nb_in_this_command(t_dll_node *node)
{
	size_t	arg_nb;

	arg_nb = 0;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_arg_token(node))
			arg_nb++;
		node = node -> next;
	}
	return (arg_nb);
}

void	add_cmd_arg(t_data *data, t_command_content *command_content,
	int processed_cmd_index)
{
	t_dll_node	*node;
	int			i;

	node = get_first_token_of_command(data, processed_cmd_index);
	command_content -> args = ft_calloc(count_arg_nb_in_this_command(node) + 2, sizeof(char *));
	if (!command_content -> args)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	(command_content -> args)[0] = ft_strdup(command_content -> name);
	if (!(command_content -> args)[0])
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	i = 1;
	while (node)
	{
		if (is_a_arg_token(node))
		{
			(command_content -> args)[i] = ft_strdup(get_token_value(node));
			if (!(command_content -> args)[0])
				return (free_command_content(command_content),
					fatal_error_clean_exit(data, MALLOC_FAILURE));
			i++;
		}
		node = node -> next;
	}
	(command_content -> args)[i] = NULL;
}

void	add_next_command_node_to_parsing(t_data *data, int processed_cmd_index)
{
	t_command_content	*command_content;
	t_dll_node			*node;

	command_content = ft_calloc(1, sizeof(t_command_content));
	if (!command_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	add_cmd_name(data, command_content, processed_cmd_index);
	add_cmd_arg(data, command_content, processed_cmd_index);
	// add_cmd_redir(data, command_content, processed_cmd_index);
	node = dll_new_node((void *)command_content);
	if (!node)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	dll_insert_tail(data -> parsing_commands, node);
}
