/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:13 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 19:04:58 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_expendable_type(t_token_type type)
{
	return (type == STRING_TK || type == DQ_TK);
}

static bool	token_value_contain_a_dollar(t_dll_node *token)
{
	return (NULL != ft_strchr(((t_token_content *)token
				-> content)-> value, '$'));
}

void	expend(t_data *data)
{
	t_dll_node	*token;

	token = data -> lexer -> linked_token -> head;
	while (token)
	{
		if (is_expendable_type(((t_token_content *)token -> content)-> type) \
	&& token_value_contain_a_dollar(token) == true)
			expend_token_value(token -> content, data);
		token = token -> next;
	}
}

//TEST : ceci est un $test "$bizzare" '$voyons voir ce qui se produit'
//TEST : "$TEST$TEST$TEST $ $ $TEST"