/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:17 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/27 10:39:29 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	print_token_type(t_token_type token_type)
{
	const char	*token_names[] = {
		"SPACE_TK",
		"STRING_TK",
		"DQ_TK",
		"SQ_TK",
		"PIPE_TK",
		"INPUT_TK",
		"OUTPUT_TK",
		"HEREDOC_TK",
		"APPEND_TK",
		"FILE_TK",
		"CMD_TK",
		"ARG_TK"
	};

	if (token_type >= SPACE_TK && token_type <= ARG_TK)
		ft_printf("%s\n", token_names[token_type]);
	else
		ft_printf("Unknown token\n");
}

void	print_token_content(t_token_content *token_content)
{
	print_token_type(token_content -> type);
	ft_printf("value = %s\n", token_content -> value);
}
