/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:25:08 by eazard            #+#    #+#             */
/*   Updated: 2024/11/07 16:36:57 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *src, char separator)
{
	bool	triger;
	size_t	index;
	size_t	cpt;

	triger = 1;
	index = 0;
	cpt = 0;
	while (src[index])
	{
		if (triger == 1 && src[index] != separator)
		{
			triger = 0;
			cpt += 1;
		}
		if (triger == 0 && src[index] == separator)
			triger = 1;
		index++;
	}
	return (cpt);
}
