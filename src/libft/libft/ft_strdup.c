/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:33:16 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:41:24 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	source_len;
	size_t	index;
	char	*duplicated_string;

	index = 0;
	source_len = ft_strlen(source);
	duplicated_string = malloc((source_len + 1) * sizeof(char));
	if (duplicated_string == NULL)
		return (NULL);
	while (index < source_len)
	{
		duplicated_string[index] = source[index];
		index ++;
	}
	duplicated_string[index] = '\0';
	return (duplicated_string);
}
