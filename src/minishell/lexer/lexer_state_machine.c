/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:18:35 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:32:56 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	init_linked_token_in_data(t_data *data)
{
	ft_printf("init linked token in data\n");
	if (data && data -> lexer)
	{
		data -> lexer -> linked_token = dll_new_list();
		ft_printf("dll_new_list ended\n");
		if (!(data -> lexer -> linked_token))
		{
			ft_printf("!(data -> lexer -> linked_token)\n");
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
		ft_printf("init_linked_token_in_data OUT\n");
	}
	else
	{	
		ft_printf("error\n");
		if (data)
			ft_printf("lexer NULL\n");
		else
			ft_printf("data NULL\n");
	}
}

static void	init_function_tab_in_data(char *(*get_token_value[])(t_data *))
{
	ft_printf("init_function_tab_in_data IN\n");
	get_token_value[SPACE_TK] = &get_next_space_value;
	get_token_value[PIPE_TK] = &get_next_pipe_value;
	get_token_value[STRING_TK] = &get_next_string_value;
	get_token_value[DQ_TK] = &get_next_db_quote_value;
	get_token_value[SQ_TK] = &get_next_s_quote_value;
	get_token_value[INPUT_TK] = &get_next_input_value;
	get_token_value[OUTPUT_TK] = &get_next_output_value;
	get_token_value[HEREDOC_TK] = &get_next_heredoc_value;
	get_token_value[APPEND_TK] = &get_next_append_value;
	ft_printf("init_function_tab_in_data OUT\n");
}

void	lexer_state_machine(t_data *data)
{
	t_token_type	token_type;

	init_linked_token_in_data(data);
	init_function_tab_in_data(data -> lexer -> get_token_value);
	ft_printf("actual_characer BEFORE\n");
	while (actual_character(data) != '\0')
	{
		ft_printf("get_token_type BEFORE\n");
		token_type = get_token_type(data);
		ft_printf("get_token_and_insert_tail BEFORE\n");
		get_next_token_and_insert_tail(data, token_type);
	}
	ft_printf("End Of Loop\n");
}
