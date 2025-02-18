/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_user_input_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/18 16:02:13 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_user_input_space(t_data *data, bool fatal)
{
	if (data && data -> user_input)
	{
		if (data -> user_input -> input)
		{
			free(data -> user_input -> input);
			(data -> user_input -> input) = NULL;
		}
		if (fatal)
		{
			free(data -> user_input);
			(data -> user_input) = NULL;
		}
	}
}
