/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:52:15 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:36:01 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_from_right(t_octet *destimation_memory__per_octet,
		const t_octet *source_memory__per_octet, size_t number_of_octet_to_copy)
{
	size_t	octet_index;

	octet_index = number_of_octet_to_copy - 1;
	while (octet_index > 0)
	{
		destimation_memory__per_octet[octet_index]
			= source_memory__per_octet[octet_index];
		octet_index--;
	}
	destimation_memory__per_octet[octet_index]
		= source_memory__per_octet[octet_index];
}

static void	ft_memmove_from_left(t_octet *destimation_memory__per_octet,
		t_octet *source_memory__per_octet, size_t number_of_octet_to_copy)
{
	size_t	octet_index;

	octet_index = 0;
	while (octet_index < number_of_octet_to_copy)
	{
		destimation_memory__per_octet[octet_index]
			= source_memory__per_octet[octet_index];
		octet_index++;
	}
}

void	*ft_memmove(void *destimation_memory,
		const void *source_memory, size_t number_of_octet_to_copy)
{
	t_octet	*destimation_memory__per_octet;
	t_octet	*source_memory__per_octet;

	if (number_of_octet_to_copy == 0)
		return (destimation_memory);
	destimation_memory__per_octet = (t_octet *)destimation_memory;
	source_memory__per_octet = (t_octet *)source_memory;
	if (destimation_memory > source_memory)
		ft_memmove_from_right(destimation_memory__per_octet,
			source_memory__per_octet, number_of_octet_to_copy);
	else if (destimation_memory < source_memory)
		ft_memmove_from_left(destimation_memory__per_octet,
			source_memory__per_octet, number_of_octet_to_copy);
	return (destimation_memory);
}
