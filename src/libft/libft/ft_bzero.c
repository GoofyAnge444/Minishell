/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:55:26 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 09:57:48 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *general_pointer, size_t null_octet_number)
{
	t_octet	*octet_pointer;
	t_octet	null_octet;
	size_t	octet_index;

	octet_pointer = (t_octet *)general_pointer;
	null_octet = 0;
	octet_index = 0;
	while (octet_index < null_octet_number)
	{
		octet_pointer[octet_index] = null_octet;
		octet_index++;
	}
	return (general_pointer);
}
