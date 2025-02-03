/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:34:38 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 16:41:08 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

size_t	dll_len(t_dll_list *list)
{
	t_dll_node	*node;
	size_t		len;

	len = 0;
	if (list)
	{
		node = list -> head;
		while (node)
		{
			len++;
			node = node -> next;
		}
	}
	return (len);
}
