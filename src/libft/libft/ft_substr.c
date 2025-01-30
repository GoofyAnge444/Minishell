/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:36:21 by eazard            #+#    #+#             */
/*   Updated: 2024/05/22 19:51:08 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_overflow_setting(char const *source,
	unsigned int substring_start_index)
{
	if (ft_strlen(source) < substring_start_index)
		return (1);
	else
		return (0);
}

static size_t	get_substring_len(char const *source,
	unsigned int substring_start_index, size_t substring_max_len)
{
	size_t	substring_len;

	substring_len = 0;
	while (source[substring_start_index + substring_len] != '\0'
		&& substring_len < substring_max_len)
		substring_len++;
	return (substring_len);
}

static char	*create_empty_string(void)
{
	char	*empty_string;

	empty_string = malloc(1);
	if (empty_string == NULL)
		return (NULL);
	*empty_string = '\0';
	return (empty_string);
}

char	*ft_substr(char const *source,
	unsigned int substring_start_index, size_t substring_max_len)
{
	size_t	index;
	char	*substring;

	if (check_overflow_setting(source, substring_start_index))
		return (create_empty_string());
	substring = malloc(get_substring_len(source,
				substring_start_index, substring_max_len) + 1);
	if (substring == NULL)
		return (NULL);
	index = 0;
	while (source[substring_start_index + index] != '\0'
		&& index < substring_max_len)
	{
		substring[index] = source[substring_start_index + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
