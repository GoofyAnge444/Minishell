/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:42:29 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 17:22:59 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

void	dll_print_list(t_dll_list *list, void (*print_content)(void *))
{
	t_dll_node	*node;

	if (list && list->head)
	{
		node = list->head;
		while (node)
		{
			print_content(node->content);
			node = node->next;
		}
	}
	else
		ft_printf("no node to print.");
}
