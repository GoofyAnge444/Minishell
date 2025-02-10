/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:08 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:06:51 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_dll_list	t_dll_list;
typedef struct s_user_input	t_user_input;
typedef struct s_lexer		t_lexer;

typedef enum e_token_type
{
	SPACE_TK,
	// FILE_TOKEN,
	// DOLLAR_TOKEN,
	// DOLLAR_FAIL,
	STRING_TK,
	DQ_TK,
	SQ_TK,
	PIPE_TK,
	INPUT_TK,
	OUTPUT_TK,
	HEREDOC_TK,
	APPEND_TK,
}	t_token_type;

typedef int	t_function;

typedef struct s_lexer
{
	t_function	get_token_content[9];
	t_dll_list	*linked_token;
}	t_lexer;

typedef struct s_user_input
{
	char	*input;
	size_t	cursor;
}	t_user_input;

void	lexer_state_machine(t_data *data);
void	get_next_token_content(t_data *data, bool (*break_condition)(char)
			, t_token_type token_type);


#endif