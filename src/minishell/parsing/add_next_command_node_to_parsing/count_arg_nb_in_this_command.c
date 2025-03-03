/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg_nb_in_this_command.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:40:20 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 16:40:41 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	count_arg_nb_in_this_command(t_dll_node *node)
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
