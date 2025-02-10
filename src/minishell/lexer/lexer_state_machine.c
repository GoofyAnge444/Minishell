/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_state_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:18:35 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:04:47 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


static void	init_linked_token_in_data(t_data *data)
{
	data -> lexer -> linked_token = dll_new_list();
	if (!(data -> lexer -> linked_token))
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}

static void	init_function_tab_in_data(void *get_token_content)
{
	(void)get_token_content;
// 	get_token_content[SPACE_TK] = &space_next_token;
// 	get_token_content[PIPE_TK] = &pipe_next_token;
// 	get_token_content[STRING_TK] = &string_next_token;
// 	get_token_content[DQ_TK] = &d_quote_next_token;
// 	get_token_content[SQ_TK] = &s_quote_next_token;
// 	get_token_content[INPUT_TK] = &input_next_token;
// 	get_token_content[OUTPUT_TK] = &output_next_token;
// 	get_token_content[HEREDOC_TK] = &heredoc_next_token;
// 	get_token_content[APPEND_TK] = &append_next_token;
}

static char	actual_character(t_data *data)
{
	return (data -> user_input -> input[data -> user_input -> cursor]);
}

static char	next_character(t_data *data)
{
	return (data -> user_input -> input[data -> user_input -> cursor + 1]);
}

static t_token_type	get_token_type(t_data *data)
{

	if (actual_character(data) == '|')
		return (PIPE_TK);
	else if (actual_character(data) == ' ')
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

void	lexer_state_machine(t_data *data)
{
	t_token_type	token_type;

	init_linked_token_in_data(data);
	init_function_tab_in_data(data -> lexer -> get_token_content);
	while (actual_character(data) != '\0')
	{
		token_type = get_token_type(data);
		ft_printf("token type : %i\n", token_type);
		break ;
		// process_next_token(data, token_type);
	}
}
