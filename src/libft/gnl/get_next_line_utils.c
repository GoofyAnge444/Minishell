/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:27:05 by eazard            #+#    #+#             */
/*   Updated: 2024/12/04 16:37:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_buffer_empty(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_buffer_len(char *buffer)
{
	size_t	buffer_begin;
	size_t	i;

	buffer_begin = 0;
	while (buffer_begin < BUFFER_SIZE && !buffer[buffer_begin])
		buffer_begin++;
	i = 0;
	while (buffer_begin + i < BUFFER_SIZE && buffer[buffer_begin + i]
		&& buffer[buffer_begin + i] != '\n')
		i++;
	if (buffer[buffer_begin + i] == '\n')
		i++;
	return (i);
}
