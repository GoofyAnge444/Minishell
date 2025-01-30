/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:32:06 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:36:00 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character_to_lower)
{
	if (character_to_lower >= 'A' && character_to_lower <= 'Z')
		return (character_to_lower + 32);
	else
		return (character_to_lower);
}
