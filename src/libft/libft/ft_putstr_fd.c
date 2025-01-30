/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:24:20 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:35:58 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *string_to_put, int file_descriptor)
{
	size_t	character_index;

	character_index = 0;
	while (string_to_put[character_index] != '\0')
	{
		ft_putchar_fd(string_to_put[character_index], file_descriptor);
		character_index++;
	}
}
