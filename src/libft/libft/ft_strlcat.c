/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:16:08 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:46:56 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination_string,
	const char *source_string, size_t buffer_size)
{
	size_t	source_string_len;
	size_t	destination_string_len;
	size_t	character_index;

	source_string_len = ft_strlen(source_string);
	destination_string_len = ft_strlen(destination_string);
	if (destination_string_len >= buffer_size)
		return (source_string_len + buffer_size);
	character_index = 0;
	while (source_string[character_index] != '\0'
		&& destination_string_len + character_index < buffer_size - 1)
	{
		destination_string[destination_string_len + character_index]
			= source_string[character_index];
		character_index++;
	}
	destination_string[destination_string_len + character_index] = '\0';
	return (destination_string_len + source_string_len);
}
