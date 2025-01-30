/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:53:55 by ange              #+#    #+#             */
/*   Updated: 2024/11/04 14:50:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int integer_to_check)
{
	if ((integer_to_check >= 'a' && integer_to_check <= 'z')
		|| (integer_to_check >= 'A' && integer_to_check <= 'Z')
		|| (integer_to_check >= '0' && integer_to_check <= '9'))
		return (1);
	else
		return (0);
}
