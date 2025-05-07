/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:09:59 by eazard            #+#    #+#             */
/*   Updated: 2025/04/30 20:52:10 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef STDLIB_H
#  define  STDLIB_H
#  include <stdlib.h>
# endif
# define VOID (void)0
# include <stdio.h>
# include "libft.h"
# include "dll.h"
# include "env.h"
# include "lexer.h"
# include "data.h"
# include "binary_tree.h"
# include "parsing.h"
# include "exec.h"

typedef struct s_lexer				t_lexer;
typedef struct s_user_input			t_user_input;
typedef struct s_data				t_data;
typedef struct s_segment_content	t_segment_content; //le mot input est pe plus approprié -- Jean

void	get_and_store_user_input(t_data *data);

#endif