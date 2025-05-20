/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:49 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/20 18:01:35 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*ajouter une node à env 
si y a =, ca va dans l'env mm si y a r apres.
Sans =, ca va dans export pas dans env.
on peut en faire plusieurs sur une ligne;
expend les dollars comme d'hab;
*/

static void	msg_invalid_export(char *str)
{
	ft_printf_fd(2, "export: '%s': not a valid identifier\n", str);
}

static bool	valid_export(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (false);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static void	print_export(t_data *data)
{
	int				i;
	t_dll_node		*temp;
	t_env_content	*env_var;
	t_env_content	*export_var;

	env_var = ft_calloc(1, sizeof(t_env_content));
	export_var = ft_calloc(1, sizeof(t_env_content));
	temp = data->env->head;
	while (temp)
	{
		env_var = temp->content;
		if (env_var->value && *env_var->value)
			printf("export %s=\"%s\"\n", env_var->name, env_var->value);
		else if (env_var->name) //si y a pas de value mais y a un name
			printf("export %s=\"\"\n", env_var->name);
		temp = temp->next;
	}
	i = 0;
	if (data->export_list || data->export_list->head)
	{
		temp = data->export_list->head;
		while (temp)
		{
			export_var = temp->content;
			printf("export %s", export_var->name);
			temp = temp->next;
		}
	}
		/*je veux dire ici que si c'est pas dans l'env, mais que c'est
			un export valide (HELLO sans = par ex), j'imprime ce truc.
			Le truc en question doit avoir éte stocké qqpart avant> 
			Je crée un tableau export ? pas besoin de stuct vu que je veux juste 
			l'afficher apres, et en supprimer aussi. juste à la parcourir.
			*/
}

static int	get_name_and_value(char *str, t_env_content *tmp_env,
		t_env_content *tmp_export, t_data *data)
{
	char	*equals;

	equals = ft_strchr(str, '=');
	if (equals)
	{
		tmp_env->name = ft_substr(str, 0, equals - str);
		if (!tmp_env->name)
		{
			free(tmp_env);
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
		tmp_env->value = ft_strdup(equals + 1);
		if (!tmp_env->value)
		{
			free(tmp_env->name);
			free(tmp_env);
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		}
	}
	else
	{
		tmp_export->name = ft_strdup(str);
		if (!tmp_export->name)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		tmp_export->value = NULL;
	}
	return (0);
}

void	ft_export(t_segment_content *content, t_data *data)
{
	int				i;
	char			**tab;
	t_env_content	*tmp_export;
	t_env_content	*tmp_env;

	tmp_env = ft_calloc(1, sizeof(t_env_content));
	tmp_export = ft_calloc(1, sizeof(t_env_content));
	tab = content->cmd_args;
	i = 1;
	if (!tab[1])
		print_export(data);
	else
	{
		while (tab[i])
		{
			if (valid_export(tab[i]) == true)
			{
				get_name_and_value(tab[i], tmp_env, tmp_export, data);	
				if (ft_strchr(tab[i], '='))
					set_var_in_list(data->env, tmp_env->name,
						tmp_env->value, data);
				else if (!ft_getenv(tmp_env->name, data))
					set_var_in_list(data->export_list, tmp_export->name,
						NULL, data);
				free_env_content(tmp_env);
				free_env_content(tmp_export);
			}
			else
				msg_invalid_export(tab[i]);
			i++;
		}
	}
}

/*
void	ft_export(t_segment_content *content, t_data *data)
{
	int				i;
	char			**add_env;
	t_env_content	*new_env;

	i = 0;
	add_env = content->cmd_args[i];

	while (add_env)
	{

		if (add_env[i] == '=')
		{
			i = 0;
			while(add_env[i] == '=')
				new_env->name = add_env[i];
			dll_insert_tail(data->env, dll_new_node(content));
		}
		i++;
	}
}
*/