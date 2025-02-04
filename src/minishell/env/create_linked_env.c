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

#include "env.h"

void	create_linked_env(t_data *data, char *env[])
{
	size_t			i;
	t_dll_list		*env_dll;
	t_dll_node		*env_node;

	i = 0;
	env_dll = dll_new_list();
	if (!env_dll)
		exit(MALLOC);
	while (env[i])
	{
		env_node = dll_new_node(NULL);
		if (!env_node)
			exit_clean(data, MALLOC);
		env_node->content = env_var_to_env_content(env[i]);
		if (!env_node -> content)
			exit_clean(data, MALLOC);
		dll_insert_tail(env_dll, env_node);
		i++;
	}
	data -> env = env_dll;
}
