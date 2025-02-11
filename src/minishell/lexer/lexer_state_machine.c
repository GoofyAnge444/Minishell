/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:18:35 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:21:48 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	init_linked_token_in_data(t_data *data)
{
	if (data && data -> lexer)
	{
		data -> lexer -> linked_token = dll_new_list();
		if (!(data -> lexer -> linked_token))
		{
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
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
	get_token_value[SPACE_TK] = &get_next_space_value;
	get_token_value[PIPE_TK] = &get_next_pipe_value;
	get_token_value[STRING_TK] = &get_next_string_value;
	get_token_value[DQ_TK] = &get_next_db_quote_value;
	get_token_value[SQ_TK] = &get_next_s_quote_value;
	get_token_value[INPUT_TK] = &get_next_input_value;
	get_token_value[OUTPUT_TK] = &get_next_output_value;
	get_token_value[HEREDOC_TK] = &get_next_heredoc_value;
	get_token_value[APPEND_TK] = &get_next_append_value;
}

void	lexer_state_machine(t_data *data)
{
	t_token_type	token_type;

	init_linked_token_in_data(data);
	init_function_tab_in_data(data -> lexer -> get_token_value);
	while (ft_printf("WHILE actual character = %c", actual_character(data)) && actual_character(data))
	{
		token_type = get_token_type(data);
		print_token_type(token_type);
		get_next_token_and_insert_tail(data, token_type);
	}
}
