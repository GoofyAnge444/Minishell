/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_clear_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:51:23 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:17 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	dll_clear_list(t_dll_list *list, void (*free_content)(void *))
{
	t_dll_node	*node;
	t_dll_node	*next_node;

	node = list->head;
	while (node)
	{
		free_content(node->content);
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(list);
}
