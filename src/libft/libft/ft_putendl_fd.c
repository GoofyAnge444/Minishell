/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ange <ange@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:29:23 by ange              #+#    #+#             */
/*   Updated: 2024/05/08 12:34:43 by ange             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_new_line_fd(int file_descriptor)
{
	ft_putchar_fd('\n', file_descriptor);
}

void	ft_putendl_fd(char *string_to_put, int file_descriptor)
{
	ft_putstr_fd(string_to_put, file_descriptor);
	put_new_line_fd(file_descriptor);
}
