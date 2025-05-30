/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_pipe_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:06:03 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:15:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_pipe_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == PIPE_TK)
		return (true);
	return (false);
}
