/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:47:17 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:35:59 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memory_to_check,
		int octet_to_look_for, size_t number_of_octet_to_check)
{
	t_octet	*memory_to_check__per_octet;
	size_t	octet_index;

	memory_to_check__per_octet = (t_octet *)memory_to_check;
	octet_index = 0;
	while (octet_index < number_of_octet_to_check)
	{
		if (memory_to_check__per_octet[octet_index]
			== (t_octet)octet_to_look_for)
			return (memory_to_check__per_octet + octet_index);
		octet_index ++;
	}
	return (NULL);
}
