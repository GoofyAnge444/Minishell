/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:28:48 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:53:49 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *source_string,
	char (*functionToApply)(unsigned int, char))
{
	unsigned int	character_index;
	char			*output_string;

	output_string = malloc(ft_strlen(source_string) + 1);
	if (output_string == NULL)
		return (0);
	character_index = 0;
	while (source_string[character_index] != '\0')
	{
		output_string[character_index]
			= functionToApply(character_index, source_string[character_index]);
		character_index++;
	}
	output_string[character_index] = '\0';
	return (output_string);
}
