/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_cmd_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:46:18 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 09:56:33 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_cmd_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == CMD_TK)
		return (true);
	return (false);
}
