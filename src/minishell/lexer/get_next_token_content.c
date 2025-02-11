/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:36 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 00:29:11 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	*get_next_token_content(t_data *data, t_token_type token_type)
{
	t_token_content	*token_content;

	token_content = ft_calloc(1, sizeof(t_token_content));
	if (!token_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	token_content -> type = token_type;
	token_content -> value
		= ((char *(*)(t_data *))(data -> lexer
				-> get_token_value)[token_type])(data);
	return (token_content);
}
