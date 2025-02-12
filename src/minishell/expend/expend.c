/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:13 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 17:37:42 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_expendable_type(t_token_type type)
{
	return (type == STRING_TK || type == DQ_TK);
}

void	expend(t_data *data)
{
	t_dll_node	*token;

	token = data -> lexer -> linked_token -> head;
	while (token)
	{
		if (is_expendable_type(((t_token_content *)token -> content)-> type) \
	&& NULL != ft_strchr(((t_token_content *)token -> content)-> value, '$'))
			expend_token_value(token -> content, data);
		token = token -> next;
	}
}

//TEST : ceci est un $test "$bizzare" '$voyons voir ce qui se produit'
//TEST : "$TEST$TEST$TEST $ $ $TEST"