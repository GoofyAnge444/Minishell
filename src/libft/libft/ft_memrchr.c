/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:56:55 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:35:58 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *memory_to_check,
		int octet_to_look_for, size_t number_of_octet_to_check)
{
	t_octet	*memory_to_check__per_octet;
	size_t	octet_index;

	memory_to_check__per_octet = (t_octet *)memory_to_check;
	octet_index = 0;
	while (octet_index + 1 < number_of_octet_to_check)
		octet_index++;
	while (octet_index > 0)
	{
		if (memory_to_check__per_octet[octet_index]
			== (t_octet)octet_to_look_for)
			return (memory_to_check__per_octet + octet_index);
		octet_index--;
	}
	if (memory_to_check__per_octet[octet_index] == (t_octet)octet_to_look_for)
		return (memory_to_check__per_octet + octet_index);
	return (NULL);
}
