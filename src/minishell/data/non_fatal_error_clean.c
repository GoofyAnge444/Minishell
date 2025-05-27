/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_fatal_error_clean.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:27 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 18:48:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	non_fatal_error_clean(t_data *data, t_non_fatal_type_error error)
{
	free_data(data, false);
	data -> non_fatal_error_occured = true;
	if (error == QUOTE_CLOSE)
		ft_printf("syntax error : unclose quote\n");
	if (error == DOUBLE_PIPE)
		ft_printf("syntax error near pipe token\n");
	if (error == REDIR_WITHOUT_STRING_FOLLOWING)
		ft_printf("syntax error near 'redir' token \n");
	if (error < HEREDOC_SIGNAL_INTERUPTION)
		data -> last_exit_code = 2; // ca ca va poser soucis plus tard
	else
		data -> last_exit_code = 128 + SIGINT;
	data -> last_non_fatal_error = error;
}
