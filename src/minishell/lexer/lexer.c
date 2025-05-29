/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:03:00 by eazard            #+#    #+#             */
/*   Updated: 2025/05/29 16:40:39 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer(t_data *data)
{
	lexer_state_machine(data);
	// dll_print_list(data ->lexer->linked_token,
	// 	(void (*)(void *))(&print_token_content));
	// ft_printf("\n\n\n");
	expend(data);
	if (check_unclose_quote(data) == true)
		non_fatal_error_clean(data, QUOTE_CLOSE);
	if (data -> non_fatal_error_occured == false)
	{
		set_up_if_heredoc_should_expend_later(data);
		merge_str_dq_sq(data);
		convert_lonely_dq_and_sq_to_str(data);
		delete_all_space_tk(data);
		if (check_redir_followed_by_string(data) == true)
			non_fatal_error_clean(data, REDIR_WITHOUT_STRING_FOLLOWING);
		if (check_each_command_has_content(data) == true)
			non_fatal_error_clean(data, DOUBLE_PIPE);
		rename_string_tk_in_appropriate_tk(data);
	}
}
