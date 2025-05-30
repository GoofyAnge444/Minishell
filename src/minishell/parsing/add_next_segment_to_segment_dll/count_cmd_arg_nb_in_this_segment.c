/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd_arg_nb_in_this_segment.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:48:01 by eazard            #+#    #+#             */
/*   Updated: 2025/03/06 09:48:02 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	count_cmd_arg_nb_in_this_segment(t_dll_node *node)
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
