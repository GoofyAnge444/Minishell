/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parsing_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:03:22 by eazard            #+#    #+#             */
/*   Updated: 2025/03/10 11:53:03 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_parsing_space(t_data *data)
{
	data -> parsing = ft_calloc(1, sizeof(t_parsing));
	if (!data -> parsing)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
