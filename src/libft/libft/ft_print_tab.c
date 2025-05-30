/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:52:31 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:06:47 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char *tab_name, char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_printf("%s[%i] = %s\n", tab_name, (int)i, tab[i]);
			i++;
		}
	}
	else
		ft_printf("%s (null) pointer\n", tab_name);
}
