/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:29:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/04 16:56:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "minishell.h"

typedef struct s_env_content	t_env_content;
typedef struct s_data			t_data;

struct s_env_content
{
	char	*name;
	char	*value;
};

t_env_content	*env_var_to_env_content(char *env_var);
void			free_env_content(t_env_content *env_content);
void			create_linked_env(t_data *data, char *env[]);

#endif