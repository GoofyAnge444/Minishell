/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:17 by ange              #+#    #+#             */
/*   Updated: 2024/05/21 13:53:38 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *source_string, int character_to_find)
{
	size_t	index;

	if ('\0' == (char)character_to_find)
		return ((char *)source_string + ft_strlen(source_string));
	index = 0;
	while (source_string[index] != '\0')
	{
		if (source_string[index] == (char)character_to_find)
			return ((char *)source_string + index);
		index++;
	}
	return ((char *)0);
}
