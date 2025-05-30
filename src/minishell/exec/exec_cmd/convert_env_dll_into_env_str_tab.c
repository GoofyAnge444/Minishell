/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_dll_into_env_str_tab.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:45:17 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 14:31:54 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	convert_env_dll_into_env_str_tab(t_data *data)
{
	size_t		i;
	t_dll_node	*env_node;
	char		**envp;

	envp = ft_calloc(1 + dll_len(data -> env), sizeof(char *));
	if (!envp)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	data -> exec -> envp = envp;
	env_node = data -> env -> head;
	i = 0;
	while (env_node)
	{
		envp[i] = ft_strjoin_with_separator(
				((t_env_content *)env_node -> content)->name,
				((t_env_content *)env_node -> content)->value, '=');
		if (!envp[i])
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		i++;
		env_node = env_node -> next;
	}
}
