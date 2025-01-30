/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:47:47 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:49:48 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination_string,
	const char *source_string, size_t buffer_size)
{
	size_t	source_string_len;
	size_t	character_index;

	source_string_len = ft_strlen(source_string);
	character_index = 0;
	if (buffer_size != 0)
	{
		while (character_index < buffer_size - 1
			&& source_string[character_index])
		{
			destination_string[character_index]
				= source_string[character_index];
			character_index++;
		}
		destination_string[character_index] = '\0';
	}
	return (source_string_len);
}
