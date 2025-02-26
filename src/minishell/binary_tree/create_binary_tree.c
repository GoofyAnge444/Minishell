/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_binary_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:29:30 by eazard            #+#    #+#             */
/*   Updated: 2025/02/20 16:58:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_binary_tree	*create_binary_tree(void *content)
{
	t_binary_tree	*new_binary_tree;

	new_binary_tree = ft_calloc(1, sizeof(t_binary_tree));
	if (!new_binary_tree)
		return (NULL);
	new_binary_tree -> content = content;
	ft_printf("binary tree created at adress %p\n", new_binary_tree);
	return (new_binary_tree);
}
