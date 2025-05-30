/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_string_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:14:09 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:35:51 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_string_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == STRING_TK)
		return (true);
	return (false);
}
