/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error_clean_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:47:51 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/18 14:54:35 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	fatal_error_clean_exit(t_data *data, t_fatal_type_error error)
{
	free_data(data, 1);
	exit(error);
}
