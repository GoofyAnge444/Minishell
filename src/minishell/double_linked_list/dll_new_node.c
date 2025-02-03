/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:14:50 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 16:28:57 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll_node	*dll_new_node(void *content)
{
	t_dll_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_dll_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	return (new_node);
}
