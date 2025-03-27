/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_linked_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:28:31 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/16 02:26:11 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	created_linked_env(t_data *data, char *env[])
{
	size_t			i;
	t_dll_node		*env_node;

	i = 0;
	while (env[i])
	{
		env_node = dll_new_node(NULL);
		if (!env_node)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		env_node->content = env_var_to_env_content(env[i]);
		if (!env_node -> content)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		dll_insert_tail(data -> env, env_node);
		i++;
	}
}
