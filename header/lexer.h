/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:08 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:03:44 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef struct s_data			t_data;
typedef struct s_dll_list		t_dll_list;
typedef struct s_user_input		t_user_input;
typedef struct s_lexer			t_lexer;
typedef struct s_token_content	t_token_content;


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


struct	s_token_content
{
	t_token_type	type;
	char			*value;
};

typedef struct s_lexer
{
	char		*(*get_token_value[9])(t_data *);
	t_dll_list	*linked_token;
}	t_lexer;

typedef struct s_user_input
{
	char	*input;
	size_t	cursor;
}	t_user_input;

void			lexer_state_machine(t_data *data);
void			*get_next_token_content(t_data *data, t_token_type token_type);
/*character utils*/
char			actual_character(t_data *data);
char			actual_character_offset(t_data *data, size_t i);
char			next_character(t_data *data);
void			moov_cursor_forward_of_one(t_data *data);
/*core function*/
t_token_type	get_token_type(t_data *data);
void			get_next_token_and_insert_tail(t_data *data,
					t_token_type token_type);
void			print_token_content(t_token_content *token_content);
void			free_token_content(t_token_content *token_content);


/*get next token value*/
char			*get_next_append_value(t_data *data);
char			*get_next_db_quote_value(t_data *data);
char			*get_next_heredoc_value(t_data *data);
char			*get_next_input_value(t_data *data);
char			*get_next_output_value(t_data *data);
char			*get_next_pipe_value(t_data *data);
char			*get_next_s_quote_value(t_data *data);
char			*get_next_space_value(t_data *data);
char			*get_next_string_value(t_data *data);







#endif