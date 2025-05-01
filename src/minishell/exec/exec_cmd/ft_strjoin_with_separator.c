/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_separator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:29:23 by ange              #+#    #+#             */
/*   Updated: 2025/05/01 14:53:57 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_strjoin_with_separator(char const *prefix, char const *suffix,
			char separtor)
{
	char	*joined_string;
	size_t	index;
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = ft_strlen(prefix);
	suffix_len = ft_strlen(suffix);
	joined_string = malloc(prefix_len + suffix_len + 2);
	if (joined_string == 0)
		return (0);
	index = 0;
	while (index < prefix_len)
	{
		joined_string[index] = prefix[index];
		index ++;
	}
	joined_string[index] = separtor;
	index = 0;
	while (index < suffix_len)
	{
		joined_string[prefix_len + 1 + index] = suffix[index];
		index++;
	}
	joined_string[prefix_len + 1 + suffix_len] = '\0';
	return (joined_string);
}
