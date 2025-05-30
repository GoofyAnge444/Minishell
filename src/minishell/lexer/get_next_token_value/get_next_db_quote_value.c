/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_db_quote_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:43:01 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/29 15:32:22 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	break_condition_db_quote(char c)
{
	return (c == '\0' || c == '"');
}

static size_t	get_db_quote_token_len(t_data *data)
{
	size_t	i;

	i = 1;
	while (break_condition_db_quote(actual_character_offset(data, i)) == false)
		i++;
	if (actual_character_offset(data, i) == '"')
		i++;
	return (i);
}

static void	skip_first_db_quote(t_data *data, char *token_value, size_t *i)
{
	token_value[(*i)] = actual_character(data);
	moov_cursor_forward_of_one(data);
	(*i)++;
}

static void	add_last_db_quote(t_data *data, char *token_value, size_t *i)
{
	token_value[(*i)] = actual_character(data);
	moov_cursor_forward_of_one(data);
	(*i)++;
}

char	*get_next_db_quote_value(t_data *data)
{
	char	*token_value;
	size_t	i;

	token_value = ft_calloc(get_db_quote_token_len(data) + 1, 1);
	if (!token_value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	i = 0;
	skip_first_db_quote(data, token_value, &i);
	while (break_condition_db_quote(actual_character(data)) == false)
	{
		token_value[i] = actual_character(data);
		moov_cursor_forward_of_one(data);
		i++;
	}
	if (actual_character(data) == '"')
		add_last_db_quote(data, token_value, &i);
	token_value[i] = '\0';
	return (token_value);
}
