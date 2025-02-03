/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:29:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 20:08:37 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef struct s_env_content	t_env_content;

struct s_env_content
{
	char	*name;
	char	*value;
};

t_env_content	*env_var_to_env_content(char *env_var);

#endif