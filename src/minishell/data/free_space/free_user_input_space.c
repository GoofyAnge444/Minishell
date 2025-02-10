/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_user_input_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 17:24:22 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_user_input_space(t_data *data)
{
	if (data && data -> user_input)
	{
		if (data -> user_input -> input)
			free(data -> user_input -> input);
		free(data -> user_input);
	}
}
