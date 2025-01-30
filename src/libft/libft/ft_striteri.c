/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:48:22 by ange              #+#    #+#             */
/*   Updated: 2024/05/27 16:03:38 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *source, void (*function_to_apply)(unsigned int,
char*))
{
	size_t	index;

	index = 0;
	while (source[index])
	{
		function_to_apply(index, source + index);
		index ++;
	}
}
