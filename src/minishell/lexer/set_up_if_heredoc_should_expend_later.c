/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_if_heredoc_should_expend_later.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:43:39 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 17:06:43 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_dll_node	*get_next_heredoc_token(t_dll_node *token)
{
	while (token && !is_a_heredoc_token(token))
		token = token->next;
	if (token)
		return (token);
	else
		return (NULL);
}

void	set_up_if_heredoc_should_expend_later(t_data *data)
{
	t_dll_node	*token;
	t_dll_node	*heredoc;

	if (data->non_fatal_error_occured == false)
	{
		token = data->lexer->linked_token->head;
		while (token)
		{
			heredoc = get_next_heredoc_token(token);
			if (!heredoc)
				return ;
			token = heredoc->next;
			while (token && is_a_space_token(token))
				token = token->next;
			while (token && (is_a_quote_token(token)
					|| is_a_string_token(token)))
			{
				if (is_a_quote_token(token))
					((t_token_content *)(heredoc->content))->heredoc__no_expend
						= true;
				token = token->next;
			}
		}
	}
}
