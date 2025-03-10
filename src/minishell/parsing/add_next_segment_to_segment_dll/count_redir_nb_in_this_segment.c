/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir_nb_in_this_segment.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:48:44 by eazard            #+#    #+#             */
/*   Updated: 2025/03/06 09:48:45 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	count_redir_nb_in_this_segment(t_dll_node *node)
{
	size_t	redir_nb;

	redir_nb = 0;
	while (node && !is_a_pipe_token(node))
	{
		if (is_a_redir_token(node))
			redir_nb++;
		node = node -> next;
	}
	return (redir_nb);
}
