/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:16:33 by ange              #+#    #+#             */
/*   Updated: 2024/05/27 11:18:46 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_character(char character_1, char character_2)
{
	return ((unsigned char)character_1 - (unsigned char)character_2);
}

int	ft_strncmp(const char *string_source_1,
	const char *string_source_2, size_t number_of_character_to_compare_at_max)
{
	size_t	character_index;

	character_index = 0;
	if (number_of_character_to_compare_at_max == 0)
		return (0);
	while (character_index + 1 < number_of_character_to_compare_at_max
		&& string_source_1[character_index] == string_source_2[character_index]
		&& string_source_1[character_index] != '\0')
		character_index++;
	return (compare_character(string_source_1[character_index],
			string_source_2[character_index]));
}
