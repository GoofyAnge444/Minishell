/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:45 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/20 15:38:10 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*enlever une variable et son contenant de notre env:
pas d'erreur s'il n'y a rien a unset (ne rien renvoyer).
ne fonctionne pas en pipe ??
*/

static void	clear_export(int i, t_segment_content *content, t_data *data)
{
	t_dll_node		*temp;
	t_dll_node		*next;
	t_env_content	*var;

	if (!data || !data->export_list || !data->export_list->head)
		return ;
	printf("export_list->head points to: %p\n", data->export_list->head);
	temp = data->export_list->head;
	if (temp == NULL || temp == (void *)0)
		return ;
	while (temp)
	{
		printf("inboucle\n");
		next = temp->next;
		var = temp->content;
		if (!ft_strcmp(var->name, content->cmd_args[i]))
		{	
			dll_clear_node(temp, (void (*)(void *))(&free_env_content));
			break ;
		}
		else
			temp = next;
	}
}

void	ft_unset(t_segment_content *content, t_data *data)
{
	int				i;
	t_dll_node		*temp;
	t_env_content	*var;

	i = 1;
	while (content->cmd_args[i])
	{
		temp = data->env->head;
		while (temp)
		{
			var = temp->content;
			if (!ft_strcmp(var->name, content->cmd_args[i]))
			{
				dll_clear_node(temp, (void (*)(void *))(&free_env_content));
				break ;
			}
				temp = temp->next;
		}
		if (data->export_list || data->export_list->head)
			clear_export(i, content, data);
		i++;
	}
}
