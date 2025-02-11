/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_and_insert_tail.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:34:54 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:19:47 by eazard           ###   ########.fr       */
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
	dll_insert_tail(data -> lexer -> linked_token, next_token);
}
