/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:12:12 by ange              #+#    #+#             */
/*   Updated: 2024/05/21 14:13:53 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *source_string,
		const char *sub_string, size_t len)
{
	size_t	source_string_index;
	size_t	sub_string_index;
	size_t	sub_string_len;

	sub_string_len = ft_strlen(sub_string);
	if (sub_string[0] == '\0')
		return ((char *)source_string);
	source_string_index = 0;
	while (source_string[source_string_index]
		&& source_string_index + sub_string_len - 1 < len)
	{
		sub_string_index = 0;
		while (source_string[source_string_index + sub_string_index]
			== sub_string[sub_string_index])
		{
			if (sub_string[sub_string_index + 1] == '\0')
				return ((char *)source_string + source_string_index);
			sub_string_index++;
		}
		source_string_index++;
	}
	return (NULL);
}
