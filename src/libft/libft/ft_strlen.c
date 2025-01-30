/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:47:51 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:50:40 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string_to_get_len)
{
	size_t	character_index;

	character_index = 0;
	while (string_to_get_len[character_index] != '\0')
		character_index++;
	return (character_index);
}
