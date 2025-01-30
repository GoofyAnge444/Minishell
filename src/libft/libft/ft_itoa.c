/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:57:52 by ange              #+#    #+#             */
/*   Updated: 2024/05/28 10:52:08 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(unsigned int absolute_value)
{
	int	cpt;

	cpt = 1;
	absolute_value /= 10;
	while (absolute_value > 0)
	{
		cpt += 1;
		absolute_value /= 10;
	}
	return (cpt);
}

static void	ft_strrev(char *str)
{
	size_t	begin;
	size_t	end;
	char	tmp;

	begin = 0;
	if (str[begin] == '\0')
		return ;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (begin < end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

static void	ft_absolute_value_to_ascii(char *str,
	unsigned int absolute_value, int is_negativ)
{
	size_t	i;

	i = 0 + is_negativ;
	str[i] = absolute_value % 10 + '0';
	absolute_value /= 10;
	i++;
	while (absolute_value > 0)
	{
		str[i] = absolute_value % 10 + '0';
		absolute_value /= 10;
		i++;
	}
	ft_strrev(str + is_negativ);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	absolute_value;

	if (n >= 0)
		absolute_value = (unsigned int)n;
	else
		absolute_value = (unsigned int)-n;
	str = ft_calloc(ft_count_digit(absolute_value) + 1 + (n < 0), 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_absolute_value_to_ascii(str, absolute_value, (n < 0));
	return (str);
}
