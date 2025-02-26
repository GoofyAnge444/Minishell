/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:28:34 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 18:45:54 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef struct s_command_content	t_command_content;
typedef struct s_redir_content		t_redir_content;
// typedef struct s_parsing			t_parsing;


struct s_command_content
{
	char		**args;
	char		*name;
	t_dll_list	**redir;
};

struct s_redir
{
	t_token_type	type;
	char			*filename;
};

// struct s_parsing
// {
// 	t_dll_list	*commands;
// };

void			parsing(t_data *data);
void			free_command_content(t_command_content *command_content);

#endif