/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:53:43 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:13:26 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memory_zone_to_set,
	int octet_set_value, size_t number_of_octet_to_set)
{
	t_octet	*memory_zone_to_set__per_octet;
	size_t	octet_index;

	memory_zone_to_set__per_octet = (t_octet *)memory_zone_to_set;
	octet_index = 0;
	while (octet_index < number_of_octet_to_set)
	{
		*(memory_zone_to_set__per_octet + octet_index)
			= (t_octet)octet_set_value;
		octet_index++;
	}
	return (memory_zone_to_set);
}
