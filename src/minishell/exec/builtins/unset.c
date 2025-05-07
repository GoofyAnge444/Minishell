/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:45 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/01 00:55:27 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*enlever une variable et son contenant de notre env:
pas d'erreur s'il n'y a rien a unset (ne rien renvoyer).
*/

void	ft_unset(t_segment_content *content, t_data *data)
{
	int				i;
	t_dll_node		*temp;
	t_env_content	*env_var;

	i = 1;
	while (content->cmd_args[i])
	{
		temp = data->env->head;
		while (temp)
		{
			env_var = temp->content;
			//printf("inside n8m %s\tvalue %s\n", env_var->name, env_var->value);
			if (!ft_strcmp(env_var->name, content->cmd_args[i]))
			{	
			//	printf("supp name %s\tvalue %s\n", env_var->name, env_var->value);
				dll_clear_node(temp, (void (*)(void *))(&free_env_content));
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}
