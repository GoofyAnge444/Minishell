/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:12:28 by eazard            #+#    #+#             */
/*   Updated: 2025/03/16 01:25:57 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include "minishell.h"

typedef struct s_binary_tree	t_binary_tree;

struct s_binary_tree
{
	t_binary_tree	*parent;
	t_binary_tree	*left_child;
	t_binary_tree	*right_child;
	void			*content;
};

t_binary_tree	*create_binary_tree(void *content);
void			clear_binary_tree(t_binary_tree *root,
					void (*free_content)(void *));
t_binary_tree	*join_binary_tree(t_binary_tree *left,
					t_binary_tree *right, void *content);
#endif