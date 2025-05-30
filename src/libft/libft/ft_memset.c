/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:53:43 by ange              #+#    #+#             */
/*   Updated: 2025/02/04 16:13:31 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memory_zone_to_set,
	int octet_set_value, size_t number_of_octet_to_set)
{
	t_octet	*memory_zone_to_set__per_octet;
	size_t	i;

	memory_zone_to_set__per_octet = (t_octet *)memory_zone_to_set;
	i = 0;
	while (i < number_of_octet_to_set)
	{
		*(memory_zone_to_set__per_octet + i)
			= (t_octet)octet_set_value;
		i++;
	}
	return (memory_zone_to_set);
}
