/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_fatal_error_clean.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:27 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 02:08:25 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*le print dans le bon fd, donc user de ft_putstr_fd.*/

#include "data.h"

void	non_fatal_error_clean(t_data *data, t_non_fatal_type_error error)
{
	free_data(data, false);
	data -> non_fatal_error_occured = true;
	if (error == QUOTE_CLOSE)
		ft_printf_fd(2, "syntax error : unclose quote\n");
	if (error == DOUBLE_PIPE)
		ft_printf_fd(2, "syntax error near pipe token\n");
	if (error == REDIR_WITHOUT_STRING_FOLLOWING)
		ft_printf_fd(2, "syntax error near 'redir' token \n");
}
