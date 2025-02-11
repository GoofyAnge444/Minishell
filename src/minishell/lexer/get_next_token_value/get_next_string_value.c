/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_string_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:43:01 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 19:46:29 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	break_condition_string(char c)
{
	// ft_printf("actual char = %c\n", c);
	return (c == '\0' || c == '\'' || c == '"'
		|| c == '|' || c == '<' || c == '>' || ft_is_white_space(c));
}

static size_t	get_string_token_len(t_data *data)
{
	size_t	i;

	i = 0;
	while (break_condition_string(actual_character_offset(data, i)))
		i++;
	return (i);
}

char	*get_next_string_value(t_data *data)
{
	char	*token_value;
	size_t	i;

	token_value = ft_calloc(get_string_token_len(data), 1);
	if (!token_value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	i = 0;
	while (break_condition_string(actual_character(data)) == false)
	{
		ft_printf("C UN MIRACLE\n");
		token_value[i] = actual_character(data);
		moov_cursor_forward_of_one(data);
		i++;
	}
	return (token_value);
}
