/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_redir_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:08:24 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 16:09:58 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	is_a_redir_token(t_dll_node *node)
{
	if (((t_token_content *)(node -> content))->type == APPEND_TK ||
	((t_token_content *)(node -> content))->type == TRUNCATE_TK || \
	((t_token_content *)(node -> content))->type == INPUT_TK || \
	((t_token_content *)(node -> content))->type == HEREDOC_TK)
		return (true);
	return (false);
}
