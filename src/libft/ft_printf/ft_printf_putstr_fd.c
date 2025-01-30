/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:24:20 by ange              #+#    #+#             */
/*   Updated: 2024/12/04 16:25:04 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putstr_fd(char *str, int fd, int *char_nb)
{
	size_t	i;

	i = 0;
	if (str == (char *)0)
		return (ft_printf_putstr_fd("(null)", fd, char_nb));
	while (str[i] != '\0')
	{
		ft_printf_putchar_fd(str[i], fd, char_nb);
		i++;
	}
}
