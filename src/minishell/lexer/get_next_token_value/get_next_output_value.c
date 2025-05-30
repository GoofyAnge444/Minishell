/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_output_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:55:06 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/27 10:51:59 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*get_next_output_value(t_data *data)
{
	char	*value;

	moov_cursor_forward_of_one(data);
	value = ft_strdup(">");
	if (!value)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	return (value);
}
