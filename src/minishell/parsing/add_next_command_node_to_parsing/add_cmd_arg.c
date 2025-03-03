/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:37:04 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 16:51:22 by eazard           ###   ########.fr       */
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
				t_command_content *command_content)
{
	(command_content -> args)[0] = ft_strdup(command_content -> name);
	if (!(command_content -> args)[0])
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

static void	add_arg_in_arg_tab(t_data *data, t_command_content *command_content,
				t_dll_node *first_token_of_cmd)
{
	t_dll_node	*node;
	int			i;

	node = first_token_of_cmd;
	i = 1;
	while (node && !is_a_pipe_token(node))
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

static void	allocate_arg_tab_space(t_data *data,
		t_command_content *command_content, t_dll_node *first_token_of_cmd)
{
	command_content -> args
		= ft_calloc(count_arg_nb_in_this_command(first_token_of_cmd) + 2, \
		sizeof(char *));
	if (!command_content -> args)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

void	add_cmd_arg(t_data *data, t_command_content *command_content,
	int processed_cmd_index)
{
	t_dll_node	*first_token_of_cmd;

	first_token_of_cmd = get_first_token_of_command(data, processed_cmd_index);
	if (there_is_cmd_tk_in_this_cmd(first_token_of_cmd))
	{
		allocate_arg_tab_space(data, command_content, first_token_of_cmd);
		add_cmd_name_in_arg_tab(data, command_content);
		add_arg_in_arg_tab(data, command_content, first_token_of_cmd);
	}
	else
		command_content -> args = NULL;
}
