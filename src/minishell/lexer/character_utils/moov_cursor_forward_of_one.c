/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov_cursor_forward_of_one.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:13:46 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:56:41 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	moov_cursor_forward_of_one(t_data *data)
{
	(data -> user_input -> cursor) += 1;
}
