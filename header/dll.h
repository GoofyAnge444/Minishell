/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:01:09 by eazard            #+#    #+#             */
/*   Updated: 2025/02/17 15:24:25 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H
# include "minishell.h"

typedef struct s_dll_node	t_dll_node;
typedef struct s_dll_list	t_dll_list;
typedef struct s_lexer		t_lexer;
typedef struct s_user_input	t_user_input;
typedef struct s_data		t_data;

struct	s_dll_node
{
	void		*content;
	t_dll_node	*next;
	t_dll_node	*prev;
	t_dll_list	*parent_list;
};

struct s_dll_list
{
	t_dll_node	*head;
	t_dll_node	*tail;
};

void		dll_print_list(t_dll_list *list, void (*print_content)(void *));
void		dll_clear_list(t_dll_list *list, void (*free_content)(void *));
void		dll_insert_tail(t_dll_list *list, t_dll_node *new_node);
void		dll_clear_node(t_dll_node *del_node, void free_content(void *));
t_dll_node	*dll_new_node(void *content);
t_dll_list	*dll_new_list(void);
t_dll_node	*dll_find_node(t_dll_list *list, void *content,
				bool (*cmp_content)(void *, void *));
size_t		dll_len(t_dll_list *list);

#endif