/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lonely_dq_and_sq_to_str.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:17:56 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 18:30:39 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*get_value_without_quote(t_dll_node *node)
{
	char	*old_value;
	char	*new_value;
	int		i;

	old_value = ((t_token_content *)(node -> content))->value;
	new_value = ft_calloc(ft_strlen(old_value) + 1, sizeof(char));
	if (!new_value)
		return (NULL);
	i = 0;
	while (old_value[i + 2])
	{
		new_value[i] = old_value[i + 1];
		i++;
	}
	return (new_value);
}

void	convert_lonely_dq_and_sq_to_str(t_data *data)
{
	char		*new_value;
	t_dll_node	*node;

	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		if (is_a_quote_token(node))
		{
			new_value = get_value_without_quote(node);
			if (!new_value)
				fatal_error_clean_exit(data, MALLOC_FAILURE);
			free(((t_token_content *)(node -> content))-> value);
			(((t_token_content *)(node -> content))-> value) = new_value;
			((t_token_content *)(node -> content))-> type = STRING_TK;
		}
		node = node -> next;
	}
}
