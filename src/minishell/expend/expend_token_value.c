/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_token_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:43 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 17:40:35 by eazard           ###   ########.fr       */
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

static char	*ft_strdup_index(char *str, size_t begin, size_t end)
{
	char	*new_str;
	size_t	i;

	new_str = ft_calloc(end - begin + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (begin + i < end)
	{
		new_str[i] = str[begin + i];
		i++;
	}
	return (new_str);
}

static void	ft_pustr(char *str)
{
	size_t	i;

	i = 0;
	write(1, "->", 2);
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write(1, "<-", 2);
	write(1, "\n", 1);
}

static char	*merge_list(t_dll_list *list)
{
	t_dll_node	*tmp_node;
	char		*final_str;
	char		*tmp_str;

	tmp_node = list -> head;
	final_str = ft_strdup("");
	if (!final_str)
		return (NULL);
	while (tmp_node)
	{
		tmp_str = ft_strjoin(final_str, (char *)(tmp_node -> content));
		free(final_str);
		if (!tmp_str)
			return (NULL);
		final_str = tmp_str;
		tmp_node = tmp_node -> next;
	}
	return (final_str);
}

void	expend_token_value(t_token_content *token_content, t_data *data)
{
	t_dll_list	*new_value_dll;
	t_dll_node	*tmp_node;
	char 		*tmp_str;
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
		tmp_str = ft_strdup_index((token_content -> value), begin, end);
		if (!tmp_str)
			return (dll_clear_list(new_value_dll, &free), fatal_error_clean_exit(data, MALLOC_FAILURE));
		tmp_node = dll_new_node(tmp_str);
		if (!tmp_node)
			return (free(tmp_str), dll_clear_list(new_value_dll, &free), fatal_error_clean_exit(data, MALLOC_FAILURE));
		dll_insert_tail(new_value_dll, tmp_node);
		begin = end;
	}
	dll_print_list(new_value_dll, (void (*)(void *))(&ft_pustr));
	new_value_str = merge_list(new_value_dll);
	if (!new_value_str)
		return (dll_clear_list(new_value_dll, &free), fatal_error_clean_exit(data, MALLOC_FAILURE));
	ft_printf("token_content new_value ->%s<-\n", new_value_str);
	free(token_content -> value);
	dll_clear_list(new_value_dll, &free);
	token_content -> value = new_value_str;
}
