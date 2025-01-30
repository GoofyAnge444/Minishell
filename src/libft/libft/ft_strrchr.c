/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:17 by ange              #+#    #+#             */
/*   Updated: 2024/05/21 13:57:09 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *source_string, int character_to_find)
{
	size_t	index;

	index = 0;
	while (source_string[index])
		index++;
	while (index > 0)
	{
		if (source_string[index] == (char)character_to_find)
			return ((char *)source_string + index);
		index--;
	}
	if (source_string[index] == (char)character_to_find)
		return ((char *)source_string + index);
	return (NULL);
}
