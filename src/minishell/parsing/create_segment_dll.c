/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_segment_dll.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:51:03 by eazard            #+#    #+#             */
/*   Updated: 2025/03/04 18:19:02 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	create_segment_dll(t_data *data)
{
	data -> parsing -> segment_dll = dll_new_list();
	if (!data -> parsing -> segment_dll)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
