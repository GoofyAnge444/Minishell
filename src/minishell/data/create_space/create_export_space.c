/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_export_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:48:57 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/16 17:42:06 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_export_space(t_data *data)
{
	data -> export_list = dll_new_list();
	if (!data -> export_list)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
