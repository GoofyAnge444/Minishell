/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_space_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:16:47 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 18:12:26 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	break_condition_space(char c)
{
	return (c == '\0' || (ft_is_white_space(c) == false));
}

static size_t	get_space_token_len(t_data *data)
{
	size_t	i;

	i = 0;
	while (break_condition_space(actual_character_offset(data, i)) == false)
		i++;
	return (i);
}

char	*get_next_space_value(t_data *data)
{
	char	*token_value;
	size_t	i;

	token_value = ft_calloc(get_space_token_len(data) + 1, 1);
	if (!token_value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	i = 0;
	while (break_condition_space(actual_character(data)) == false)
	{
		token_value[i] = actual_character(data);
		moov_cursor_forward_of_one(data);
		i++;
	}
	// token_value[i] = '\0';
	return (token_value);
}
