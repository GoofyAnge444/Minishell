/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_s_quote_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:43:01 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 19:46:29 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	break_condition_s_quote(char c)
{
	return (c == '\0' || c == '\'');
}

static size_t	get_s_quote_token_len(t_data *data)
{
	size_t	i;

	i = 1;
	while (break_condition_s_quote(actual_character_offset(data, i)) == false)
		i++;
	if (actual_character_offset(data, i) == '\'')
		i++;
	return (i);
}

static void	skip_first_s_quote(t_data *data, char *token_value, size_t *i)
{
	token_value[(*i)] = actual_character(data);
	moov_cursor_forward_of_one(data);
	(*i)++;
}

static void	add_last_s_quote(t_data *data, char *token_value, size_t *i)
{
	token_value[(*i)] = actual_character(data);
	moov_cursor_forward_of_one(data);
	(*i)++;
}

char	*get_next_s_quote_value(t_data *data)
{
	char	*token_value;
	size_t	i;

	token_value = ft_calloc(get_s_quote_token_len(data) + 1, 1);
	if (!token_value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	i = 0;
	skip_first_s_quote(data, token_value, &i);
	while (break_condition_s_quote(actual_character(data)) == false)
	{
		token_value[i] = actual_character(data);
		moov_cursor_forward_of_one(data);
		i++;
	}
	if (actual_character(data) == '\'')
		add_last_s_quote(data, token_value, &i);
	// token_value[i] = '\0';
	return (token_value);
}
