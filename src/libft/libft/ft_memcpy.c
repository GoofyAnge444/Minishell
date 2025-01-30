/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:14:22 by ange              #+#    #+#             */
/*   Updated: 2024/05/27 16:09:34 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *memory_destination,
	const void *memory_source,
	size_t number_of_octet_to_copy)
{
	t_octet	*octet_pointer__memory_destination;
	t_octet	*octet_pointer__memory_source;
	size_t	octet_index;

	if (!memory_destination && !memory_source)
		return (NULL);
	octet_index = 0;
	octet_pointer__memory_destination
		= (unsigned char *)memory_destination;
	octet_pointer__memory_source
		= (unsigned char *)memory_source;
	while (octet_index < number_of_octet_to_copy)
	{
		octet_pointer__memory_destination[octet_index]
			= octet_pointer__memory_source[octet_index];
		octet_index++;
	}
	return (memory_destination);
}
