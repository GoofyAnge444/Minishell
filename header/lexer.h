/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:08 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/04 17:19:13 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "minishell.h"

typedef enum e_tokentype
{
	SPACE_TK,
	FILE_TOKEN,
	DOLLAR_TOKEN,
	DOLLAR_FAIL,
	STRING_TOKEN,
	DQ_TOKEN,
	SQ_TOKEN,
	PIPE_TK,
	INPUT_TK,
	OUTPUT_TK,
	HEREDOC_TK,
	APPEND_TK,
}	t_tokentype;

#endif