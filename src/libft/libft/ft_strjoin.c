/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:29:23 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:01:36 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	char	*joined_string;
	size_t	index;
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = ft_strlen(prefix);
	suffix_len = ft_strlen(suffix);
	joined_string = malloc(prefix_len + suffix_len + 1);
	if (joined_string == 0)
		return (0);
	index = 0;
	while (index < prefix_len)
	{
		joined_string[index] = prefix[index];
		index ++;
	}
	index = 0;
	while (index < suffix_len)
	{
		joined_string[prefix_len + index] = suffix[index];
		index++;
	}
	joined_string[prefix_len + suffix_len] = '\0';
	return (joined_string);
}
