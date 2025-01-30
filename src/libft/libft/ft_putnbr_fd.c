/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:31:31 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 11:57:19 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int number_to_put, int file_descriptor)
{
	unsigned int	absolute_value;

	if (number_to_put < 0)
	{
		ft_putchar_fd('-', file_descriptor);
		absolute_value = (unsigned int)-number_to_put;
	}
	else
		absolute_value = (unsigned int)number_to_put;
	if (absolute_value > 9)
		ft_putnbr_fd((int)(absolute_value / 10), file_descriptor);
	ft_putchar_fd(((int)(absolute_value % 10) + '0'), file_descriptor);
}
