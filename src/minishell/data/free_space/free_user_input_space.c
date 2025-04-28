/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_user_input_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:51:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/04/23 16:13:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_user_input_space(t_data *data, bool fatal)
{
	// ft_printf("free_user_input_space IN\n");
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
