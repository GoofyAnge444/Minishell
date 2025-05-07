/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:03:50 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/07 04:24:13 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	add_to_export_list(char *name, t_data *data)
{
	t_env_content	*tmp_export;

	if (!ft_getenv(name, data))
	{
	}
}

t_env_content	*create_env_content(const char *name,
		const char *value, t_data *data)
{
	t_env_content	*env;

	env = ft_calloc(1, sizeof(t_env_content));
	if (!env)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	env->name = ft_strdup(name);
	if (!env->name)
		return (free(env), fatal_error_clean_exit(data, MALLOC_FAILURE), NULL);
	if (value)
		env->value = ft_strdup(value);
	else
		env->value = NULL;
	return (env);
}

void	ft_set_export(t_data *data, char *name)
{
	t_dll_node		*temp;
	t_env_content	*env;

	temp = data->env->head;
	while (temp)
	{
		env = temp->content;
		if (!ft_strcmp(env->name, name))
			return ;// Déjà dans env → rien à faire
		temp = temp->next;
	}

	temp = data->export_list->head;
	while (temp)
	{
		env = temp->content;
		if (!ft_strcmp(env->name, name))
			return ; // Déjà dans export → rien à faire
		temp = temp->next;
	}
	env = create_env_content(name, NULL, data);
	if (!env)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	dll_insert_tail(data->export_list, dll_new_node(env));
}
