/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:25:07 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:23:40 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token_type	get_token_type(t_data *data)
{

	if (actual_character(data) == '|')
		return (PIPE_TK);
	else if (ft_is_white_space(actual_character(data)))
		return (SPACE_TK);
	else if (actual_character(data) == '<')
	{
		if (next_character(data) != '<')
			return (INPUT_TK);
		return (HEREDOC_TK);
	}
	else if (actual_character(data) == '>')
	{
		if (next_character(data) != '>')
			return (OUTPUT_TK);
		return (APPEND_TK);
	}
	else if (actual_character(data) == '\'')
		return (SQ_TK);
	else if (actual_character(data) == '"')
		return (DQ_TK);
	else
		return (STRING_TK);
}
