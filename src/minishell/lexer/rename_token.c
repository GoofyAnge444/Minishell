/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:00:40 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:41:00 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	rename_infile_outfile_eof(t_data *data)
{
	t_dll_node	*token;

	token = data -> lexer -> linked_token -> head;
	while (token)
	{
		if (is_a_redir_token(token))
		{
			// if append, rename file
			// if troncate, rename file
			// if input, rename file
			// if here_doc, rename OEF
		}
		token = token -> next;
	}
}

void	rename_token(t_data *data)
{
	if (data -> non_fatal_error_occured == false)
	{
		rename_infile_outfile_eof(data);
		// rename_cmd(data);
		// rename_arg(data);
	}
}
