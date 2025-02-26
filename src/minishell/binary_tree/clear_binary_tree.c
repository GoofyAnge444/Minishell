/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_binary_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:44:49 by eazard            #+#    #+#             */
/*   Updated: 2025/02/20 17:01:40 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

void	clear_binary_tree(t_binary_tree *root, void (*free_content)(void *))
{
	if (root -> left_child)
		clear_binary_tree(root -> left_child, free_content);
	if (root -> right_child)
		clear_binary_tree(root -> right_child, free_content);
	if (free_content && root -> content)
		free_content(root -> content);
	free(root);
	ft_printf("binary_tree_cleared\n");
}

