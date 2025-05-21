/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:20:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/13 01:40:52 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_getenv(char *name, t_data *data)
{
	t_dll_node		*temp;
	t_env_content	*env_var;

	if (!name || !data)
		return (NULL);
	temp = data->env->head;
	while (temp)
	{
		env_var = temp->content;
		if (!ft_strcmp(env_var->name, name))
			return (env_var->value);
		temp = temp->next;
	}
	return (NULL);
}

// void	ft_set_env(t_env_content *tmp_env, t_data *data)
// 	//trouver un moyen dinserer un name et value tsa comme en bas.
// {
// 	t_dll_node		*temp;
// 	t_env_content	*env_var;

// 	temp = data->env->head;
// 	while (temp)
// 	{
// 		env_var = temp->content;
// 		/*printf("inside n8m %s\tvalue %s\n", env_var->name, env_var->value);*/
// 		if (!ft_strcmp(env_var->name, tmp_env->name))
// 		{	
// 			/*printf("added name %s\tvalue %s\n", env_var->name, env_var->value);*/
// 			free(env_var->value);
// 			env_var->value = ft_strdup(tmp_env->value);
// 			if (!env_var->value)
// 				fatal_error_clean_exit(data, MALLOC_FAILURE);
// 			return ;
// 		}
// 		temp = temp->next;
// 	}
// 	env_var = ft_calloc(1, sizeof(t_env_content));
// 	if (!env_var)
// 		fatal_error_clean_exit(data, MALLOC_FAILURE);
// 	env_var->name = ft_strdup(tmp_env->name);
// 	env_var->value = ft_strdup(tmp_env->value);
// 	if (!env_var->name || !env_var->value)
// 	{
// 		free(env_var->name);
// 		free(env_var->value);
// 		free(env_var);
// 		fatal_error_clean_exit(data, MALLOC_FAILURE);
// 	}
// 	dll_insert_tail(data->env, dll_new_node(tmp_env));
// }

// void	ft_set_env_var(const char *name, const char *value, t_data *data)
// {
// 	t_env_content	tmp;

// 	tmp.name = ft_strdup(name);
// 	tmp.value = ft_strdup(value);
// 	if (!tmp.name || !tmp.value)
// 	{
// 		free(tmp.name);
// 		free(tmp.value);
// 		fatal_error_clean_exit(data, MALLOC_FAILURE);
// 	}
// 	ft_set_env(&tmp, data);
// 	free(tmp.name);
// 	free(tmp.value);
// }
