/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:09:59 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 16:27:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef STDLIB_H
#  define  STDLIB_H
#  include <stdlib.h>
# endif
# include <fcntl.h>
# define VOID (void)0
# include "libft.h"
# include "dll.h"
# include "env.h"
# include "lexer.h"
# include "data.h"
# include "binary_tree.h"
# include "parsing.h"
# include "exec.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>

typedef struct s_lexer			t_lexer;
typedef struct s_user_input		t_user_input;
typedef struct s_data			t_data;
typedef struct s_exec			t_exec;


void	get_and_store_user_input(t_data *data);

#endif