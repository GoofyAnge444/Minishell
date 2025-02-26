/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parsing_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:51:03 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 18:10:42 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_parsing_space(t_data *data)
{
	data -> parsing_commands = dll_new_list();
	if (!data -> parsing_commands)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
