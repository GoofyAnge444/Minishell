/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:21:21 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/16 17:50:34 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "minishell.h"

typedef struct s_lexer		t_lexer;
typedef struct s_data		t_data;
typedef struct s_dll_list	t_dll_list;
typedef struct s_user_input	t_user_input;
typedef int					t_bool;
typedef struct s_parsing	t_parsing;
typedef struct s_env		t_env;
typedef struct s_export		t_export;

typedef enum e_fatal_type_error
{
	NOTHING,
	MALLOC_FAILURE,
}			t_fatal_type_error;

typedef enum e_non_fatal_type_error
{
	QUOTE_CLOSE,
	REDIR_WITHOUT_STRING_FOLLOWING,
	DOUBLE_PIPE,
	// OPEN,
}			t_non_fatal_type_error;

struct s_data
{
	// t_data_ex		*par;
	// t_exec			*head;
	// int				code_reset;
	t_dll_list		*env;
	t_dll_list		*export_list;
	t_user_input	*user_input;
	t_parsing		*parsing;
	t_lexer			*lexer;
	bool			non_fatal_error_occured;
	// pid_t			*pids;
	// int				pid_count;
};

void	init_data(t_data *data, char *env[]);
/*create space*/
void	create_user_input_space(t_data *data);
void	create_lexer_space(t_data *data);
void	create_linked_env_space(t_data *data);
void	create_export_space(t_data *data);
void	create_parsing_space(t_data *data);
//void	create_fatal_error_space(t_data *data); // on taff sur ca
/*exit*/
void	fatal_error_clean_exit(t_data *data, t_fatal_type_error error);
void	non_fatal_error_clean(t_data *data, t_non_fatal_type_error error);
/*free*/
//void	free_fatal_error_space(t_data *data, bool fatal);
void	free_data(t_data *data, bool fatal);
void	free_lexer_space(t_data *data, bool fatal);
void	free_linked_env_space(t_data *data, bool fatal);
void	free_export_space(t_data *data, bool fatal);
void	free_user_input_space(t_data *data, bool fatal);
void	free_parsing_space(t_data *data, bool fatal);
/*bool utils*/
//bool	non_fatal_error_occured(t_data *data);

#endif