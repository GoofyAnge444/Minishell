/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_expend_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:36:51 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 13:18:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*merge_expend_list(t_dll_list *expend_list)
{
	t_dll_node	*tmp_node;
	char		*final_str;
	char		*tmp_str;

	tmp_node = expend_list -> head;
	final_str = ft_strdup("");
	if (!final_str)
		return (NULL);
	while (tmp_node)
	{
		tmp_str = ft_strjoin(final_str, (char *)(tmp_node -> content));
		free(final_str);
		if (!tmp_str)
			return (NULL);
		final_str = tmp_str;
		tmp_node = tmp_node -> next;
	}
	return (final_str);
}
