/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error_clean_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:47:51 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:11 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	fatal_error_clean_exit(t_data *data, t_type_error error)
{
	free_data(data);
	exit(error);
}
