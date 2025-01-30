/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:46:11 by ange              #+#    #+#             */
/*   Updated: 2024/05/27 11:22:42 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_empty_string(void)
{
	char	*empty_string;

	empty_string = malloc(1);
	if (empty_string == NULL)
		return (NULL);
	*empty_string = '\0';
	return (empty_string);
}

static bool	is_character_in_separator_set(char character,
		char const *separator_set)
{
	size_t	index;

	index = 0;
	while (separator_set[index] != '\0')
	{
		if (character == separator_set[index])
			return (1);
		index++;
	}
	return (0);
}

static size_t	get_begin_index(const char *source_string,
		char const *separator_set)
{
	size_t	begin_index;

	begin_index = 0;
	while (source_string[begin_index] != '\0'
		&& is_character_in_separator_set(source_string[begin_index],
			separator_set))
		begin_index++;
	return (begin_index);
}

static size_t	get_end_index(const char *source_string,
	char const *separator_set)
{
	size_t	end_index;

	end_index = ft_strlen(source_string) - 1;
	while (end_index > 0
		&& is_character_in_separator_set(source_string[end_index],
			separator_set))
		end_index--;
	return (end_index);
}

char	*ft_strtrim(const char *source_string, char const *separator_set)
{
	size_t	begin_index;
	size_t	end_index;
	size_t	trimed_string_len;
	size_t	index;
	char	*trimed_string;

	begin_index = get_begin_index(source_string, separator_set);
	if (source_string[begin_index] == '\0')
		return (create_empty_string());
	end_index = get_end_index(source_string, separator_set);
	trimed_string_len = end_index - begin_index + 1;
	trimed_string = malloc(trimed_string_len + 1);
	if (trimed_string == NULL)
		return (NULL);
	index = 0;
	while (begin_index + index <= end_index)
	{
		trimed_string[index] = source_string[begin_index + index];
		index++;
	}
	trimed_string[index] = 0;
	return (trimed_string);
}
