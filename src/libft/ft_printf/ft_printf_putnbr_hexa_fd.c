/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_hexa_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:14:38 by eazard            #+#    #+#             */
/*   Updated: 2024/12/04 16:25:03 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_put_caphex_fd(unsigned int n, int fd, int *char_nb)
{
	const char	*hex_base;

	hex_base = "0123456789ABCDEF";
	if (n > 15)
		ft_printf_put_caphex_fd(n / 16, fd, char_nb);
	ft_printf_putchar_fd(hex_base[n % 16], fd, char_nb);
}

void	ft_printf_put_lowhex_fd(unsigned int n, int fd, int *char_nb)
{
	const char	*hex_base;

	hex_base = "0123456789abcdef";
	if (n > 15)
		ft_printf_put_lowhex_fd(n / 16, fd, char_nb);
	ft_printf_putchar_fd(hex_base[n % 16], fd, char_nb);
}

static void	reverse_put_str_fd(char *str, int fd, int *char_nb)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0)
	{
		ft_printf_putchar_fd(str[i], fd, char_nb);
		i--;
	}
	ft_printf_putchar_fd(str[i], fd, char_nb);
}

void	ft_printf_put_hex_adress_fd(unsigned long adress, int fd, int *char_nb)
{
	const char	*hex_base;
	char		hex_adress_rev[HEX_ADRESS_SIZE + 1];
	size_t		i;

	if (adress == 0)
		return (ft_printf_putstr_fd("(nil)", fd, char_nb));
	hex_base = "0123456789abcdef";
	i = 0;
	while (adress > 15)
	{
		hex_adress_rev[i] = hex_base[adress % 16];
		adress /= 16;
		i++;
	}
	hex_adress_rev[i] = hex_base[adress];
	hex_adress_rev[i + 1] = '\0';
	ft_printf_putstr_fd("0x", fd, char_nb);
	reverse_put_str_fd(hex_adress_rev, fd, char_nb);
}
