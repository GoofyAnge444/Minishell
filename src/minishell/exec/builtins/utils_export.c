/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:20:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/26 19:38:30 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	verif_in_export(char *in_env, t_data *data)
{
	t_dll_node		*temp;
	t_env_content	*in_exp;

	temp = data->export_list->head;
	while (temp)
	{
		in_exp = temp->content;
		if (!ft_strcmp(in_exp->name, in_env))
		{
			dll_clear_node(temp, (void (*)(void *))(&free_env_content));
			break ;
		}
		temp = temp->next;
	}
}

static t_env_content	*ft_new_content(char *name, char *value, t_data *data)
{
	t_env_content	*tmp;

	tmp = ft_calloc(1, sizeof(t_env_content)); // Si la variable n'existe pas dans la liste, on la crée et on l'ajoute
	if (!tmp)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	tmp->name = ft_strdup(name);
	if (!tmp->name)
	{
		free(tmp);
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	}
	if (value != NULL)
	{
		tmp->value = ft_strdup(value);
		if (!tmp->value)
		{
			free(tmp->name);
			free(tmp);
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
		verif_in_export(tmp->name, data); //on vérifie dans export si la nouvelle variable y existe, puis on supprime.
	}
	else
		tmp->value = NULL;
	return (tmp);
}

static void	ft_replace_value(t_env_content *tmp, char *new_value, t_data *data)
{
	free(tmp->value);
	if (new_value != NULL)
	{
		tmp->value = ft_strdup(new_value);
		if (!tmp->value)
		{
			free(tmp->name);
			free(tmp);
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
	}
	else
		tmp->value = NULL;
}

/*fonction generale pour env et export en fonction de la list envoyé.*/
void	set_var_in_list(t_dll_list *list, char *name,
	char *new_value, t_data *data)
{
	t_dll_node		*node;
	t_env_content	*tmp;

	node = list->head;
	while (node)
	{
		tmp = node->content;
		if (!ft_strcmp(tmp->name, name)) // Si la variable existe déjà (même nom), on met à jour sa valeur
			return (ft_replace_value(tmp, new_value, data), (void)0);
		node = node->next;
	}
	tmp = ft_new_content(name, new_value, data);
	dll_insert_tail(list, dll_new_node(tmp)); // On insère la nouvelle variable à la fin de la liste
}

/*pcq on a des limites de lignes, création de cette merveille*/
void	freeing_experience(t_env_content *tmp_env, t_data *data)
{
	free_env_content(tmp_env);
	fatal_error_clean_exit(data, MALLOC_FAILURE);
}
