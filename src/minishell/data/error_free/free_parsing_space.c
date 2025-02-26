/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 18:46:50 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_parsing_space(t_data *data, bool fatal)
{
	if (data -> parsing_commands)
	{
		if (fatal)
			dll_clear_list(data -> parsing_commands,
				(void (*)(void *))(&free_command_content));
	}
}
