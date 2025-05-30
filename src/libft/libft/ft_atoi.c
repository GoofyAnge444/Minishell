/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:58:35 by ange              #+#    #+#             */
/*   Updated: 2025/05/30 14:53:33 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_a_sign(char character)
{
	if (character == '+' || character == '-')
		return (1);
	else
		return (0);
}

static int	ft_sign_value(char character)
{
	int	error_value;

	error_value = 0;
	if (character == '-')
		return (-1);
	else if (character == '+')
		return (1);
	else
		return (error_value);
}

int	ft_atoi(const char *string)
{
	size_t	index;
	int		absolute_value;
	int		sign;

	sign = 1;
	index = 0;
	absolute_value = 0;
	while (ft_is_white_space(string[index]))
		index++;
	if (ft_is_a_sign(string[index]))
	{
		sign = ft_sign_value(string[index]);
		index++;
	}
	while (ft_isdigit((int)(string[index])))
	{
		absolute_value = absolute_value * 10 + (string[index] - '0');
		index++;
	}
	return (sign * absolute_value);
}

long long	ft_atoll(const char *string)
{
	size_t		index;
	long long	absolute_value;
	long long	sign;

	sign = 1;
	index = 0;
	absolute_value = 0;
	while (ft_is_white_space(string[index]))
		index++;
	if (ft_is_a_sign(string[index]))
	{
		sign = ft_sign_value(string[index]);
		index++;
	}
	while (ft_isdigit((long)(string[index])))
	{
		absolute_value = absolute_value * 10 + (string[index] - '0');
		index++;
	}
	return (sign * absolute_value);
}
