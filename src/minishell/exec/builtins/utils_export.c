/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:03:50 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/20 17:54:24 by cboma-ya         ###   ########.fr       */
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

static void	ft_new_content(t_env_content *tmp, char *name,
	char *value, t_data *data)
{
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
	//t_env_content	*export_content;

	if (list == data->export_list)
		printf("⚠️ INSERTION DANS EXPORT_LIST ⚠️\n");
	///a supprimer
	node = list->head;
	while (node)
	{
		tmp = node->content;
		if (!ft_strcmp(tmp->name, name)) // Si la variable existe déjà (même nom), on met à jour sa valeur
			return (ft_replace_value(tmp, new_value, data), (void)0);
		node = node->next;
	}
	ft_new_content(tmp, name, new_value, data);
	//export_content = data->export_list->head;
	// verif(tmp, data->export_list, data->env, data);
	dll_insert_tail(list, dll_new_node(tmp)); // On insère la nouvelle variable à la fin de la liste
	// free_env_content(tmp);
}
