/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_and_insert_tail.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:34:54 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:27:50 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	get_next_token_and_insert_tail(t_data *data, t_token_type token_type)
{
	t_dll_node		*next_token;

	next_token = dll_new_node(NULL);
	if (!next_token)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	next_token -> content = get_next_token_content(data, token_type);
	ft_printf("dll_insert_tail BEFORE\n");
	dll_insert_tail(data -> lexer -> linked_token, next_token);
}
