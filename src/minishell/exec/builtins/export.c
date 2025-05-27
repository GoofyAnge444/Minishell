/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:49 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/27 18:35:35 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*ajouter une node à env 
si y a =, ca va dans l'env mm si y a r apres.
Sans =, ca va dans export pas dans env.
on peut en faire plusieurs sur une ligne;
expend les dollars comme d'hab;
*/

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
	t_dll_node		*temp;
	t_env_content	*var;

	temp = data->env->head;
	while (temp)
	{
		var = temp->content;
		if (var->value && *var->value)
			printf("export %s=\"%s\"\n", var->name, var->value);
		else if (var->name)
			printf("export %s=\"\"\n", var->name);
		temp = temp->next;
	}
	if (data->export_list && data->export_list->head)
	{
		temp = data->export_list->head;
		while (temp)
		{
			var = temp->content;
			printf("export %s\n", var->name);
			temp = temp->next;
		}
	}
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
			freeing_experience(tmp_env, data);
		tmp_env->value = ft_strdup(equals + 1);
		if (!tmp_env->value)
			freeing_experience(tmp_env, data);
	}
	else
	{
		tmp_export->name = ft_strdup(str);
		if (!tmp_export->name)
			freeing_experience(tmp_export, data);
		tmp_export->value = NULL;
	}
	return (0);
}

static void	export_in_list(char **tab, t_data *data, int i)
{
	t_env_content	*tmp_export;
	t_env_content	*tmp_env;

	tmp_env = ft_calloc(1, sizeof(t_env_content));
	if (!tmp_env)
	{
		set_last_exit_code(data, 1);
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	}
	tmp_export = ft_calloc(1, sizeof(t_env_content));
	if (!tmp_export)
	{
		set_last_exit_code(data, 1);
		free(tmp_env);
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	}
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

void	ft_export(t_cmd_content *content, t_data *data)
{
	int				i;
	char			**tab;

	tab = content->cmd_args;
	i = 1;
	if (!tab[1])
		print_export(data);
	else
	{
		while (tab[i])
		{
			if (valid_export(tab[i]) == true)
				export_in_list(tab, data, i);
			else
			{
				set_last_exit_code(data, 1);
				ft_printf_fd(2,
					"mimishell: export: '%s': not a valid identifier\n", tab[i]);
			}
			i++;
		}
	}
}
