/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:35:00 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 16:35:36 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_cmd_name(t_data *data, t_command_content *command_content,
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
else
	command_content -> name = NULL;
}
