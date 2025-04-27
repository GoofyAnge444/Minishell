/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/04/27 18:21:15 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_exec_space(t_data *data, bool fatal)
{
	if (data && data -> exec)
	{
		if (data -> exec -> cmd_dll)
			free(data -> exec -> cmd_dll);
		if (fatal)
		{
			free(data -> exec);
		}
	}
}
