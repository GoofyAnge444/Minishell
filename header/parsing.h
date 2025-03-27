/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:28:34 by eazard            #+#    #+#             */
/*   Updated: 2025/03/27 19:53:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "minishell.h"

typedef struct s_segment_content	t_segment_content; //le mot input est pe plus approprié
typedef struct s_redir				t_redir;
typedef struct s_parsing			t_parsing;

struct 
s_parsing
{
	t_dll_list	*segment_dll;
	int			segment_count;
	int			segment_processed;
};

struct	s_segment_content
{
	char		**cmd_args;
	char		*cmd_name;// c'est cmd_arg[0] donc why?
	t_redir		**redir_tab;
};

struct	s_redir
{
	int				redir_type;
	char			*filename;
};

void	ft_echo(t_segment_content *content, t_data *data);
void	ft_pwd(void);


void			parsing(t_data *data);
void			create_segment_dll(t_data *data);
void			free_segment_content(t_segment_content *segment_content);
void			free_redir_tab(t_redir **redir_tab);
size_t			count_cmd_arg_nb_in_this_segment(t_dll_node *node);
size_t			count_redir_nb_in_this_segment(t_dll_node *node);
void			add_next_segment_to_segment_dll(t_data *data);
void			add_cmd_name_to_segment(t_data *data,
					t_segment_content *segment_content);
void			add_cmd_arg_to_segment(t_data *data,
					t_segment_content *segment_content);
void			add_redir_tab_to_segment(t_data *data,
					t_segment_content *segment_content);

/* UTILS*/
char			*get_token_value(t_dll_node *node);
void			print_segment_content(t_segment_content *content);
t_dll_node		*get_first_token_of_segment(t_data *data);

#endif