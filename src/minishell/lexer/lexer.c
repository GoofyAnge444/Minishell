/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:03:00 by eazard            #+#    #+#             */
/*   Updated: 2025/02/18 18:14:11 by eazard           ###   ########.fr       */
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
	if (check_double_pipe(data) == true)
		non_fatal_error_clean(data, DOUBLE_PIPE);
	if (check_double_redir(data) == true)
		non_fatal_error_clean(data, DOUBLE_REDIR);
}
