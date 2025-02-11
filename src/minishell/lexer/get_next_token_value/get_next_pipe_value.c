/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_pipe_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:54:04 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:52:07 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*get_next_pipe_value(t_data *data)
{
	char	*str_dup;

	moov_cursor_forward_of_one(data);
	str_dup = ft_strdup("|");
	if (!str_dup)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	return (str_dup);
}
