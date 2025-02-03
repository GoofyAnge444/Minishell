/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_clear_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:41 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 16:14:13 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	dll_clear_node(t_dll_node *del_node, void *free_content(void *))
{
	if (del_node->content)
		free_content(del_node->content);
	if (!del_node->next)
	{
		del_node->prev->next = NULL;
		del_node->parent_list->tail = del_node->prev;
	}
	else if (!del_node->prev)
	{
		del_node->next->prev = NULL;
		del_node->parent_list->head = del_node->next;
	}
	else
	{
		del_node->prev->next = del_node->next;
		del_node->next->prev = del_node->prev;
	}
	free(del_node);
}
