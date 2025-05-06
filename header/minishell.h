/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:09:59 by eazard            #+#    #+#             */
/*   Updated: 2025/05/06 16:50:27 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef STDLIB_H
#  define  STDLIB_H
#  include <stdlib.h>
# endif
# include <fcntl.h>
# include <unistd.h>
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
# include <sys/wait.h>
# include <signal.h>
# include "my_signal.h"
# include <sys/stat.h>
# include <errno.h>

extern int		g_last_exit_code;

typedef struct s_lexer			t_lexer;
typedef struct s_user_input		t_user_input;
typedef struct s_data			t_data;
typedef struct s_exec			t_exec;

void	get_and_store_user_input(t_data *data);
char	*get_user_input(char *prompt);
void	print_result_for_dev(t_data *data);

#endif