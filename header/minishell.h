/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:09:59 by eazard            #+#    #+#             */
/*   Updated: 2025/02/04 17:40:40 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef STDLIB_H
#  define  STDLIB_H
#  include <stdlib.h>
# endif
# define VOID (void)0
# include "libft.h"
# include "dll.h"
# include "env.h"
# include "lexer.h"
# include "data.h"

void	get_and_store_user_input(t_data *data);

#endif