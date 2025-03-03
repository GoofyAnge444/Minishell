/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:08 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/03 18:29:14 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef struct s_data			t_data;
typedef struct s_dll_list		t_dll_list;
typedef struct s_dll_node		t_dll_node;
typedef struct s_user_input		t_user_input;
typedef struct s_lexer			t_lexer;
typedef struct s_token_content	t_token_content;
typedef enum e_token_type		t_token_type;

enum e_token_type
{
	SPACE_TK,
	STRING_TK,
	DQ_TK,
	SQ_TK,
	PIPE_TK,
	INPUT_TK,
	OUTPUT_TK,
	HEREDOC_TK,
	APPEND_TK,
	FILE_TK,
	CMD_TK,
	ARG_TK
};

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
void			lexer(t_data *data);
t_token_type	get_token_type(t_data *data);
void			get_next_token_and_insert_tail(t_data *data,
					t_token_type token_type);
void			print_token_type(t_token_type token_type);
void			print_token_content(t_token_content *token_content);
void			free_token_content(t_token_content *token_content);
void			delete_all_space_tk(t_data *data);

/*TOKEN BOOL UTILS*/
bool			is_a_pipe_token(t_dll_node *node);
bool			is_a_redir_token(t_dll_node *node);
bool			is_a_quote_token(t_dll_node *node);
bool			is_a_string_token(t_dll_node *node);
bool			is_a_file_token(t_dll_node *node);
bool			is_a_cmd_token(t_dll_node *node);
bool			is_a_arg_token(t_dll_node *node);




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

/*expend*/
void			expend(t_data *data);
void			expend_token_value(t_token_content *token_content,
					t_data *data);
void			replace_dollar_in_expend_list(t_dll_list *list, t_data *data);
void			create_expend_list(t_token_content *token_content, t_data *data,
					t_dll_list *expend_dll);
char			*merge_expend_list(t_dll_list *expend_list);

/*merge dq,sq and str*/
void			merge_str_dq_sq(t_data *data);
char			*ft_strjoin_dq_sq(char *prefix, char *suffix,
					t_token_type prefix_type, t_token_type suffix_type);
void			convert_lonely_dq_and_sq_to_str(t_data *data);

/*syntax error check*/
bool			check_unclose_quote(t_data *data);
bool			check_redir_followed_by_string(t_data *data);
bool			check_each_command_has_content(t_data *data);
#endif