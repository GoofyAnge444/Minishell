/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:40:27 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 19:40:27 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_dll_list	*cp_env_to_dll(char *env[])
{
	size_t		i;
	char		**env_var;
	t_dll_list	*env_dll;
	t_dll_node	*env_node;

	i = 0;
	env_var = NULL;
	env_dll = dll_new_list();
	env_node = env_dll->head;

	while (env[i])
	{
		env_var = ft_split(env[i], '=');
		ft_printf("env = %s", env[i]);
		env_node = dll_new_node(env[i]);
		env_node->parent_list = env_dll;

		env_node->content = *env_var_to_env_node(env[i]);

		dll_insert_tail(env_dll, env_node);
		i++;
	}
}
