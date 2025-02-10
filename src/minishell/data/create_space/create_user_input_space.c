/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_user_input_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:43:34 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:12:26 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_user_input_space(t_data *data)
{
	data -> user_input = ft_calloc(1, (sizeof(struct s_user_input)));
	if (!data -> user_input)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
