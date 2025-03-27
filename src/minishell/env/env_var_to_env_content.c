/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_to_env_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:32:11 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/18 08:20:30 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static size_t	get_name_len(char *env_var)
{
	size_t	name_len;

	name_len = 0;
	while (env_var && env_var[name_len] != '\0' && env_var[name_len] != '=')
		name_len++;
	return (name_len);
}

static size_t	get_value_len(char *env_var)
{
	size_t	value_len;
	size_t	name_len;

	value_len = 0;
	name_len = get_name_len(env_var);
	while (env_var && env_var[name_len + 1 + value_len] != '\0')
		value_len++;
	return (value_len);
}

static void	write_name_in_node(t_env_content *env_content, char *env_var)
{
	size_t	i;

	i = 0;
	while (env_var && env_var[i] && env_var[i] != '=')
	{
		(env_content -> name)[i] = env_var[i];
		i++;
	}
	env_content -> name[i] = '\0';
}

static void	write_value_in_node(t_env_content *env_content, char *env_var)
{
	size_t	i;
	size_t	name_len;

	i = 0;
	name_len = get_name_len(env_var);
	while (env_var && env_var[name_len + 1 + i])
	{
		(env_content -> value)[i] = env_var[name_len + 1 + i];
		i++;
	}
	(env_content -> value)[i] = '\0';
}

t_env_content	*env_var_to_env_content(char *env_var)
{	
	t_env_content	*env_content;

	env_content = ft_calloc(1, sizeof(t_env_content));
	if (!env_content)
		return (NULL);
	env_content -> name = ft_calloc(get_name_len(env_var) + 1, 1);
	if (!env_content -> name)
		return (free(env_content), NULL);
	env_content -> value = ft_calloc(get_value_len(env_var) + 1, 1);
	if (!env_content -> value)
		return (free(env_content -> name), free(env_content), NULL);
	write_name_in_node(env_content, env_var);
	write_value_in_node(env_content, env_var);
	return (env_content);
}
