/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:29:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/10 11:53:22 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"

typedef struct s_user_input		t_user_input;
typedef struct s_env_content	t_env_content;
typedef struct s_lexer			t_lexer;
typedef struct s_data			t_data;
typedef struct s_env			t_env;

struct s_env_content
{
	char	*name;
	char	*value;
};

// struct s_env
// {
// 	t_dll_list	*env_dll;
// };

t_env_content	*env_var_to_env_content(char *env_var);
void			free_env_content(t_env_content *env_content);
void			created_linked_env(t_data *data, char **env);

#endif