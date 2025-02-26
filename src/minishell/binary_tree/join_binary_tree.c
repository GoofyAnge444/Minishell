/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_binary_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:07:07 by eazard            #+#    #+#             */
/*   Updated: 2025/02/20 17:10:02 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_binary_tree	*join_binary_tree(t_binary_tree *left
			, t_binary_tree *right, void *content)
{
	t_binary_tree	*root;

	root = create_binary_tree(content);
	if (!root)
		return (NULL);
	root -> left_child = left;
	root -> right_child = right;
	ft_printf("%p and %p joined in %p\n", left, right, root);
	return (root);
}
