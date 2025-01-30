/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:39 by eazard            #+#    #+#             */
/*   Updated: 2024/12/04 16:25:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	logic(const char **str, va_list args, int *char_nb)
{
	if (**str == 'c')
		ft_printf_putchar_fd(va_arg(args, int), 1, char_nb);
	else if (**str == 's')
		ft_printf_putstr_fd(va_arg(args, char *), 1, char_nb);
	else if (**str == 'p')
		ft_printf_put_hex_adress_fd(va_arg(args, unsigned long), 1, char_nb);
	else if (**str == 'd')
		ft_printf_put_int_fd(va_arg(args, int), 1, char_nb);
	else if (**str == 'i')
		ft_printf_put_int_fd(va_arg(args, int), 1, char_nb);
	else if (**str == 'u')
		ft_printf_put_unsigned_int_fd(va_arg(args, unsigned int), 1, char_nb);
	else if (**str == 'x')
		ft_printf_put_lowhex_fd(va_arg(args, unsigned int), 1, char_nb);
	else if (**str == 'X')
		ft_printf_put_caphex_fd(va_arg(args, unsigned int), 1, char_nb);
	else if (**str == '%')
		ft_printf_putchar_fd('%', 1, char_nb);
	else
		return ;
	*str += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_nb;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	char_nb = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			logic(&str, args, &char_nb);
		}
		else
		{
			ft_printf_putchar_fd(*str, 1, &char_nb);
			str++;
		}
	}
	va_end(args);
	return (char_nb);
}
