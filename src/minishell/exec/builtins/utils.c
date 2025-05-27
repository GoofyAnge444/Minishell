/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:40:41 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/27 18:34:34 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
cherche la node qui a pour nom "name" dans l'env
*/
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
		if (ft_strcmp(env_var->name, name))
			return (env_var->value);
		temp = temp->next;
	}
	return (NULL);
}
