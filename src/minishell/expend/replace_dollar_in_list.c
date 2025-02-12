/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_in_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:44:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 18:10:12 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool	node_is_dollar_node(char *content)
{
	return ('$' == content[0]);
}

static bool	cmp_content(void *env_content, void *var_to_find)
{
	return (ft_strcmp(((t_env_content *)env_content)->name,
				(char *)var_to_find));
}

static void	replace_dollar(t_dll_node *expend_node, t_data *data)
{
	t_dll_node	*env_node;
	char		*tmp_str;

	env_node = dll_find_node(data ->env,
			(expend_node -> content) + 1, &cmp_content);
	if (!env_node)
		tmp_str = ft_strdup("");
	else
		tmp_str = ft_strdup(((t_env_content *)(env_node -> content))-> value);
	if (!tmp_str)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	free(expend_node -> content);
	expend_node -> content = tmp_str;
}

void	replace_dollar_in_list(t_dll_list *list, t_data *data)
{
	t_dll_node	*tmp_node;

	tmp_node = list -> head;
	while (tmp_node)
	{
		if (true == node_is_dollar_node((void *)(tmp_node -> content)))
			replace_dollar(tmp_node, data);
		tmp_node = tmp_node -> next;
	}
}

// TEST : $USER$USER$USER$HOME