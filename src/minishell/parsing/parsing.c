/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:42 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 18:49:50 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_command_content(t_command_content *command_content)
{
	if (command_content)
	{
		if (command_content -> args)
			ft_free_tab(command_content -> args);
		if (command_content -> name)
			free(command_content ->name);
		if (command_content -> redir)
			ft_free_tab(command_content -> redir);
		free(command_content);
	}
}

void	add_next_command(t_data *data, int processed_command_nb)
{
	t_command_content	*command_content;
	t_dll_node			*node;

	command_content = ft_calloc(1, sizeof(t_command_content));
	if (!command_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	add_cmd_name(data, command_content, processed_command_nb);
	add_cmd_arg(data, command_content, processed_command_nb);
	add_cmd_redir(data, command_content, processed_command_nb);
	node = dll_new_node((void *)command_content);
	if (!node)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	dll_insert_tail(data -> parsing_commands, node);
}

void	parsing(t_data *data)
{

}

