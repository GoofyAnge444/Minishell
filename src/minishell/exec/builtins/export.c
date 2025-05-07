/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:49 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/07 04:02:54 by cboma-ya         ###   ########.fr       */
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
	return (1);
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

static void	print_export(t_env_content *content,
		t_env_content *export_content, t_data *data)
{
	int				i;
	t_dll_node		*temp;
	t_env_content	*env_var;

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
	temp = data->export_list->head;
	while ()
	{
		printf("export %s", data->export_content->vars[i]);
		i++;
	}
		/*je veux dire ici que si c'est pas dans l'env, mais que c'est
			un export valide (HELLO sans = par ex), j'imprime ce truc.
			Le truc en question doit avoir éte stocké qqpart avant> 
			Je crée un tableau export ? pas besoin de stuct vu que je veux juste 
			l'afficher apres, et en supprimer aussi. juste à la parcourir.
			*/
}

static int	get_name_and_value(char *str, t_env_content *tmp_env,
		char *tmp_export, t_data *data)
{
	char	*equals;
	char	*env_value;
	int		i;

	equals = ft_strchr(str, '=');
	if (equals)
	{
		tmp_env->name = ft_substr(str, 0, equals - str);
		tmp_env->value = ft_strdup(equals + 1);
	}
	else
	{
		env_value = ft_getenv(str, data);
		if (env_value)
			//si c'est dans l'env et défini, on sort.
			return (0);
		else
			tmp_export = ft_strdup(str);
	}
	return (0);
}

void	ft_export(t_segment_content *content, t_data *data)
{
	int				i;
	char			*str;
	char			*tmp_export;
	t_env_content	*tmp_env;

	str = content->cmd_args;
	i = 1;
	if (!str[1])
		print_export(data->env->head->content, data->export_list->head->content, data);
	else
	{
		while (str[i])
		{
			get_name_and_value(str[i], tmp_env, tmp_export, data);
			if (valid_export(str) == false)
				msg_invalid_export(str[i]);
			// else 
			// {

			// }
			else if (ft_strchr(str[i], '=') || !ft_getenv(tmp_env->name, data))
			{
				ft_set_env_var(tmp_env->name, tmp_env->value, data);
			}
			free(tmp_env->name);
			free(tmp_env->value);
			free(tmp_export);
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