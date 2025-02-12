/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:13 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 16:34:46 by eazard           ###   ########.fr       */
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

	ft_printf("expend IN\n\n");
	token = data -> lexer -> linked_token -> head;
	while (token)
	{
		if (is_expendable_type(((t_token_content *)token -> content)-> type) \
	&& NULL != ft_strchr(((t_token_content *)token -> content)-> value, '$'))
			expend_token_value(token -> content, data);
		token = token -> next;
	}
	ft_printf("expend OUT\n\n");
}

//TEST : ceci est un $test "$bizzare" '$voyons voir ce qui se produit'