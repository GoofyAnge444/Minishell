/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:21:21 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:14:52 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "minishell.h"

typedef struct s_lexer		t_lexer;
typedef struct s_data		t_data;
typedef struct s_dll_list	t_dll_list;
typedef struct s_user_input	t_user_input;


typedef enum e_type_error
{
	MALLOC_FAILURE,
    // QUOTE_CLOSE,
	NOTHING,
    // OPEN,
}			t_type_error;

struct s_data
{
	t_lexer			*lexer;
    // t_data_ex        *par;
    // t_exec            *head;
    // int                code_reset;
	t_dll_list		*env;
	unsigned char	exit_code;
	t_user_input	*user_input;
    // pid_t            *pids;
    // int                pid_count;
};

void	init_data(t_data *data, char *env[]);
/*create space*/
void	create_user_input_space(t_data *data);
void	create_lexer_space(t_data *data);
void	create_linked_env_space(t_data *data);
/*exit*/
void	fatal_error_clean_exit(t_data *data, t_type_error error);
/*free*/
void	free_data(t_data *data);
void	free_lexer_space(t_data *data);
void	free_linked_env_space(t_data *data);
void	free_user_input_space(t_data *data);

#endif