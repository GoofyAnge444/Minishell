/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:36 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:08:33 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	get_next_token_content(t_data *data, bool (*break_condition)(char)
		, t_token_type token_type)
{
	(void)token_type;
	(void)data;
	(void)break_condition;
	// t_token_content *token_content;
	
	// token_content = ft_calloc(sizeof(t_token_content));
	// if (!token_content)
	// 	fatal_error_clean_exit(data, MALLOC_FAILURE);
	// token -> type = token_type;
	// token -> content = get_token_content(t_data, break_condition);
	// return (token_content)
}
