/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:03:50 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/16 18:42:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	verif_in_export(t_env_content *in_env, t_data *data)
{
	t_dll_node		*temp;
	t_env_content	*var;

	temp = data->export_list->head;
	while (temp)
	{
		var = temp->content;
		if (!ft_strcmp(var->name, in_env->name))
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
	if (value != NULL && value[0] != '\0')
	{
		tmp->value = ft_strdup(value);
		if (!tmp->value)
		{
			free(tmp->name);
			free(tmp);
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
		verif_in_export(tmp->name, data);
	}
	else
		tmp->value = NULL;
}

void	ft_replace_value(t_env_content *tmp, char *name,
	char *new_value, t_data *data)
{
	free(tmp->value);
	if (new_value != NULL && new_value[0] != '\0')
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
	return ;
}

/*fonction generale pour env et export en fonction de la list envoyé.*/
void	set_var_in_list(t_dll_list *list, char *name,
	char *new_value, t_data *data)
{
	t_dll_node		*node;
	t_env_content	*tmp;
	t_env_content	*export_content;


	printf("[set_var_in_list] list=%p | name=%s | value=%s\n",
		list, name, value ? value : "NULL");

	if (list == data->export_list)
		printf("⚠️ INSERTION DANS EXPORT_LIST ⚠️\n");
	///a supprimer
	node = list->head;
	while (node)
	{
		tmp = node->content;
		if (!ft_strcmp(tmp->name, name)) // Si la variable existe déjà (même nom), on met à jour sa valeur
			ft_replace_value(tmp, name, new_value, data);
		node = node->next;
	}
	ft_new_content(tmp, name, new_value, data);
	//export_content = data->export_list->head;
	/*
	- si il est dans l'export : on l'y supprime apres son ajout dans env.
  si : y a pas de egal et il est pas dans env ->
  	 -si il est dans export -> on fait rien.
	 -si il est pas dans export -> on l'y ajoute.*/	
	verif(tmp, data->export_list, data->env, data);
	dll_insert_tail(list, dll_new_node(tmp)); // On insère la nouvelle variable à la fin de la liste
}

// static void	verif(t_env_content *tmp, t_dll_list *export,
// 	t_dll_list *env, t_data *data)
// {
	
// }

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

// void	ft_set_export(t_data *data, char *name)
// {
// 	t_dll_node		*temp;
// 	t_env_content	*env;

// 	temp = data->env->head;
// 	while (temp)
// 	{
// 		env = temp->content;
// 		if (!ft_strcmp(env->name, name))
// 			return ;// Déjà dans env → rien à faire
// 		temp = temp->next;
// 	}

// 	temp = data->export_list->head;
// 	while (temp)
// 	{
// 		env = temp->content;
// 		if (!ft_strcmp(env->name, name))
// 			return ; // Déjà dans export → rien à faire
// 		temp = temp->next;
// 	}
// 	env = create_env_content(name, NULL, data);
// 	if (!env)
// 		fatal_error_clean_exit(data, MALLOC_FAILURE);
// 	dll_insert_tail(data->export_list, dll_new_node(env));
// }
