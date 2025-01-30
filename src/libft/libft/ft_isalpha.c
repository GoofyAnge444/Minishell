/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:17:21 by ange              #+#    #+#             */
/*   Updated: 2024/05/09 12:01:20 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int integer_to_check)
{
	if ((integer_to_check >= 'a' && integer_to_check <= 'z')
		|| (integer_to_check >= 'A' && integer_to_check <= 'Z'))
		return (1);
	else
		return (0);
}
