/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:13 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 15:10:25 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_expendable_type(t_token_type type, t_dll_node *token)
{
	t_dll_node	*last_non_whitespace_token;

	if (type == STRING_TK || type == DQ_TK)
	{
		last_non_whitespace_token = token -> prev;
		while (last_non_whitespace_token
			&& is_a_space_token(last_non_whitespace_token))
			last_non_whitespace_token = last_non_whitespace_token -> prev;
		if (last_non_whitespace_token
			&& is_a_heredoc_token(last_non_whitespace_token))
			return (false);
		else
			return (true);
	}
	return (false);
}

static bool	token_value_contain_a_dollar(t_dll_node *token)
{
	return (NULL != ft_strchr(((t_token_content *)token->content)->value, '$'));
}

void	expend(t_data *data)
{
	t_dll_node	*token;
	char		*new_value;

	if (data->non_fatal_error_occured == false)
	{
		token = data->lexer->linked_token->head;
		while (token)
		{
			if (is_expendable_type(((t_token_content *)token->content)->type,
					token)
				&& token_value_contain_a_dollar(token) == true)
			{
				new_value
					= expend_value(data,
						((t_token_content *)token->content)->value);
				free(((t_token_content *)token->content)->value);
				((t_token_content *)token->content)->value = new_value;
			}
			token = token->next;
		}
	}
}

// TEST : ceci est un $test "$bizzare" '$voyons voir ce qui se produit'
// TEST : "$TEST$TEST$TEST $ $ $TEST"