/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/03/08 19:56:00 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_parsing_space(t_data *data, bool fatal)
{
	if (data && data -> parsing)
	{
		if (data -> parsing -> segment_dll)
		{
			dll_clear_list(data -> parsing -> segment_dll,
				(void (*)(void *))(&free_segment_content));
			data -> parsing -> segment_dll = NULL;
		}
		if (fatal)
		{
			free(data -> parsing);
			data -> parsing = NULL;
		}
	}
}
