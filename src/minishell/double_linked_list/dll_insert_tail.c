/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_insert_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:55:48 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 16:05:21 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

static bool	is_list_empty(t_dll_list *list)
{
	return (!(list -> tail));
}

void	dll_insert_tail(t_dll_list *list, t_dll_node *new_node)
{
	if (is_list_empty(list) == false)
	{
		list -> tail -> next = new_node;
		new_node->prev = list->tail;
		list -> tail = new_node;
		new_node -> parent_list = list;
	}
	else
	{
		list -> tail = new_node;
		list -> head = new_node;
		new_node -> parent_list = list;
	}
}
