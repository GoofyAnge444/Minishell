/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_token_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:43 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 16:35:23 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	is_dollar_char(char c)
{
	if (ft_isalnum(c))
		return (true);
	return (false);
}

static size_t	get_dollar_end(char *value, size_t begin)
{
	size_t	end;

	end = begin + 1;
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

void	expend_token_value(t_token_content *token_content, t_data *data)
{
	t_dll_list	*new_value_dll;
	char		*new_value_str;
	size_t		begin;
	size_t		end;

	ft_printf("~ expend a token content ~ \n");
	ft_printf("%s\n", token_content -> value);

	new_value_dll = dll_new_list();
	if (!new_value_dll)
		fatal_error_clean_exit(data, MALLOC_FAILURE);

	begin = 0;
	while ((token_content -> value)[begin])
	{
		if ('$' == (token_content -> value)[begin])
			end = get_dollar_end(token_content -> value, begin);
		else
			end = get_str_end(token_content -> value, begin);
		ft_printf("begin : ->%c<-\nend :->%c<-\n", (token_content -> value)[begin],
			(token_content -> value)[end]);
		begin = end;
	}
	(void)new_value_str;
}
