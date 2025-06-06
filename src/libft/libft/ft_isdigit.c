/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:22:45 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 11:23:29 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int integer_to_check)
{
	if ((integer_to_check >= '0' && integer_to_check <= '9'))
		return (1);
	else
		return (0);
}
