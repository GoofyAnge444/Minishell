/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:50:55 by ange              #+#    #+#             */
/*   Updated: 2024/05/21 13:48:21 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *memory_1, void *memory_2, size_t number_octet_to_compare)
{
	t_octet	*memory_1__per_octet;
	t_octet	*memory_2__per_octet;
	size_t	octet_index;

	if (number_octet_to_compare == 0)
		return (0);
	memory_1__per_octet = (t_octet *)memory_1;
	memory_2__per_octet = (t_octet *)memory_2;
	octet_index = 0;
	while (memory_1__per_octet[octet_index] == memory_2__per_octet[octet_index]
		&& octet_index + 1 < number_octet_to_compare)
		octet_index++;
	return (memory_1__per_octet[octet_index]
		- memory_2__per_octet[octet_index]);
}
