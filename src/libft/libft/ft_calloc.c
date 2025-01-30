/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:38 by ange              #+#    #+#             */
/*   Updated: 2024/05/22 13:28:35 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	size_t	index;
	size_t	allocated_octet_number;
	t_octet	*allocated_memory_adress;
	t_octet	null_octet;

	if ((element_count != 0 && element_count != 0)
		&& (size_t)-1 / element_count < element_size)
		return (NULL);
	allocated_octet_number = element_count * element_size;
	allocated_memory_adress = malloc(allocated_octet_number);
	if (!allocated_memory_adress)
		return (NULL);
	index = 0;
	null_octet = 0;
	while (index < allocated_octet_number)
	{
		allocated_memory_adress[index] = null_octet;
		index++;
	}
	return (allocated_memory_adress);
}
