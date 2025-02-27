/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:28:34 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:03:34 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef struct s_command_content	t_command_content;
typedef struct s_redir				t_redir;
// typedef struct s_parsing			t_parsing;

struct	s_command_content
{
	char		**args;
	char		*name;
	t_redir		**redir;
};

struct	s_redir
{
	int				redir_type;
	char			*filename;
};

// struct s_parsing
// {
// 	t_dll_list	*commands;
// };

void			parsing(t_data *data);
void			free_command_content(t_command_content *command_content);
void			rename_token(t_data *data);
void			add_next_command_node_to_parsing(t_data *data,
					int processed_command_nb);

/* UTILS*/
char			*get_token_value(t_dll_node *node);
void			print_command_content(t_command_content *content);
t_dll_node		*get_first_token_of_command(t_data *data,
					int processed_cmd_index);

#endif