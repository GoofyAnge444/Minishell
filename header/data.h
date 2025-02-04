/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:21:21 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/04 17:56:02 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_dll_list	t_dll_list;

typedef enum e_type_error
{
	MALLOC,
    // QUOTE_CLOSE,
    NOTHING,
    // OPEN,
}    t_type_error;

struct s_data
{
    // t_lex            *lex;
    // t_data_ex        *par;
    // t_exec            *head;
    // int                code_reset;
	t_dll_list		*env;
	unsigned char	exit_code;
	char			*user_input;
    // pid_t            *pids;
    // int                pid_count;
};

void	free_data(t_data *data);
void	init_data(t_data *data, char *env[]);
void	exit_clean(t_data *data, t_type_error error);

#endif