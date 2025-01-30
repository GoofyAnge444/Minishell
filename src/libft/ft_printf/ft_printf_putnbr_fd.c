/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:31:31 by ange              #+#    #+#             */
/*   Updated: 2024/12/04 16:25:01 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_put_int_fd(int n, int fd, int *char_nb)
{
	unsigned int	abs;

	if (n < 0)
	{
		ft_printf_putchar_fd('-', fd, char_nb);
		abs = (unsigned int)-n;
	}
	else
		abs = (unsigned int)n;
	if (abs > 9)
		ft_printf_put_int_fd((int)(abs / 10), fd, char_nb);
	ft_printf_putchar_fd(((int)(abs % 10) + '0'), fd, char_nb);
}

void	ft_printf_put_unsigned_int_fd(unsigned int n, int fd, int *char_nb)
{
	unsigned int	abs;

	abs = n;
	if (abs > 9)
		ft_printf_put_unsigned_int_fd((abs / 10), fd, char_nb);
	ft_printf_putchar_fd(((abs % 10) + '0'), fd, char_nb);
}
