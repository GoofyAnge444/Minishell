/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_new_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:29:11 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 16:34:13 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_dll_list	*dll_new_list(void)
{
	t_dll_list	*new_list;

	new_list = ft_calloc(1, sizeof(t_dll_list));
	if (!new_list)
		return (NULL);
	return (new_list);
}
