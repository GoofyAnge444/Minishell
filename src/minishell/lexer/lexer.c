/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:03:00 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 17:39:42 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer(t_data *data)
{
	lexer_state_machine(data);
	expend(data);
	if (check_unclose_quote(data) == true)
		non_fatal_error_clean(data, QUOTE_CLOSE);
	merge_str_dq_sq(data);
	delete_all_space_tk(data);
	if (check_redir_followed_by_string(data) == true)
		non_fatal_error_clean(data, REDIR_WITHOUT_STRING_FOLLOWING);
	if (check_each_command_has_content(data) == true)
		non_fatal_error_clean(data, DOUBLE_PIPE);
	rename_token(data);
}
