/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_arg_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:46:18 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:17:13 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_arg_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == ARG_TK)
		return (true);
	return (false);
}
