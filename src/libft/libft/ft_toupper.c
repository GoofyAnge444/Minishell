/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:27:09 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 09:54:12 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character_to_upper)
{
	if (character_to_upper >= 'a' && character_to_upper <= 'z')
		return (character_to_upper - 32);
	else
		return (character_to_upper);
}
