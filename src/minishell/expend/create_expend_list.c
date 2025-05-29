/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_expend_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:17:15 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 16:38:48 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char	*ft_strdup_index(char *str, size_t begin, size_t end)
{
	char	*new_str;
	size_t	i;

	new_str = ft_calloc(end - begin + 1, 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (begin + i < end)
	{
		new_str[i] = str[begin + i];
		i++;
	}
	return (new_str);
}

static bool	is_dollar_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

static size_t	get_dollar_end(char *value, size_t begin)
{
	size_t	end;

	end = begin + 1;
	if (value[end] == '?')
		return (end + 1);
	while (value[end] && is_dollar_char(value[end]))
		end++;
	return (end);
}

static size_t	get_str_end(char *value, size_t begin)
{
	size_t	end;

	end = begin + 1;
	while (value[end] && value[end] != '$')
		end++;
	return (end);
}
/*
expend_list est une dll avec pour value un char*
*/
void	create_expend_list(char *token_value, t_data *data,
	t_dll_list *expend_dll)
{
	char		*tmp_str;
	t_dll_node	*tmp_node;
	size_t		begin;
	size_t		end;

	begin = 0;
	while ((token_value)[begin])
	{
		if ('$' == (token_value)[begin])
			end = get_dollar_end(token_value, begin);
		else
			end = get_str_end(token_value, begin);
		tmp_str = ft_strdup_index((token_value), begin, end);
		if (!tmp_str)
			return (dll_clear_list(expend_dll, &free),
				fatal_error_clean_exit(data, MALLOC_FAILURE));
		tmp_node = dll_new_node(tmp_str);
		if (!tmp_node)
			return (free(tmp_str), dll_clear_list(expend_dll, &free),
				fatal_error_clean_exit(data, MALLOC_FAILURE));
		dll_insert_tail(expend_dll, tmp_node);
		begin = end;
	}
}
