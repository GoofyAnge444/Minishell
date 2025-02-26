/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_quote_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:33:39 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:33:40 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_quote_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == DQ_TK ||
		((t_token_content *)(node -> content))->type == SQ_TK)
		return (true);
	return (false);
}
