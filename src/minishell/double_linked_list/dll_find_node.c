/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_find_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:56:23 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:24 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll_node	*dll_find_node(t_dll_list *list, void *content,
					bool (*cmp_content)(void *, void *))
{
	t_dll_node	*node;

	if (list && list -> head)
	{
		node = list->head;
		while (node)
		{
			if (cmp_content(node->content, content))
				return (node);
			else
				node = node->next;
		}
	}
	return (NULL);
}
