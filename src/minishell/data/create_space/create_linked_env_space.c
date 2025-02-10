/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:40:27 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/03 19:40:27 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_linked_env_space(t_data *data)
{
	data -> env = dll_new_list();
	if (!data -> env)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
