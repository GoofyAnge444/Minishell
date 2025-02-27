/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:32:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_parsing_space(t_data *data, bool fatal)
{
	(void)fatal;
	if (data -> parsing_commands)
	{
		dll_clear_list(data -> parsing_commands,
			(void (*)(void *))(&free_command_content));
		data -> parsing_commands = NULL;
	}
}
