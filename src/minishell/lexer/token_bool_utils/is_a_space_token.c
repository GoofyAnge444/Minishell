/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_space_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:36:45 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 15:08:26 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_space_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == SPACE_TK)
		return (true);
	return (false);
}
