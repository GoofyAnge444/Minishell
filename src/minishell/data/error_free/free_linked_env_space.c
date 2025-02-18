/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked_env_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:47:26 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/18 17:05:43 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_linked_env_space(t_data *data)
{
	if (data && data -> env)
	{
		dll_clear_list(data -> env, (void (*)(void *))(&free_env_content));
		data -> env = NULL;
	}
}
