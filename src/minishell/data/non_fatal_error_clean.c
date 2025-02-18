/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_fatal_error_clean.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:27 by eazard            #+#    #+#             */
/*   Updated: 2025/02/18 18:15:25 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	non_fatal_error_clean(t_data *data, t_non_fatal_type_error error)
{
	free_data(data, 0);
	data -> non_fatal_error_occured = true;
	if (error == QUOTE_CLOSE)
		ft_printf("syntax error : unclose quote\n");
	if (error == DOUBLE_PIPE)
		ft_printf("syntax error : successive pipe\n");
	if (error == DOUBLE_REDIR)
		ft_printf("syntax error : successive redirection\n");
}
