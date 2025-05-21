/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_export_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:29:34 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/16 17:42:10 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_export_space(t_data *data, bool fatal)
{
	if (fatal && data && data -> export_list)
	{
		dll_clear_list(data -> export_list,
			(void (*)(void *))(&free_env_content));
		data -> export_list = NULL;
	}
}
