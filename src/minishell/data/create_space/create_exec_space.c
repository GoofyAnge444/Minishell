/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_exec_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:25 by eazard            #+#    #+#             */
/*   Updated: 2025/04/27 17:50:26 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_exec_space(t_data *data)
{
	data -> exec = ft_calloc(1, sizeof(t_exec));
	if (!data -> exec)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
