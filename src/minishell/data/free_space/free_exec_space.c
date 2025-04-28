/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 15:29:39 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_exec_space(t_data *data, bool fatal)
{
	if (data && data -> exec)
	{
		if (data -> exec -> cmd_dll)
		{
			dll_clear_list(data -> exec -> cmd_dll,
				(void (*)(void *))(&free_cmd_content));
			data -> exec -> cmd_dll = NULL;
		}
		if (fatal)
		{
			free(data -> exec);
			data -> exec = NULL;
		}
	}
}
