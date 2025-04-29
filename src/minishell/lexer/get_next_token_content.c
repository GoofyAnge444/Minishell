/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:36 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/04/29 14:46:27 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


// static bool	last_token_is_a_heredoc_and_this_token_is_str(t_data *data,
// 		t_token_type type)
// {
// 	if (data->lexer->linked_token->tail)
// 		return ((is_a_heredoc_token(data->lexer->linked_token->tail))
// 			&& type == STRING_TK);
// 	else
// 		return (false);
// }

void	*get_next_token_content(t_data *data, t_token_type token_type)
{
	t_token_content	*token_content;

	token_content = ft_calloc(1, sizeof(t_token_content));
	if (!token_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	// if (last_token_is_a_heredoc_and_this_token_is_str(data, token_type))
	// 	token_content->type = FILE_TK;
	// else
	token_content->type = token_type;
	token_content->value
		= ((char *(*)(t_data *))(data->lexer->get_token_value)
		[token_type])(data);
	return (token_content);
}
