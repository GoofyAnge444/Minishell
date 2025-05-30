/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_character_offset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:26:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 18:08:40 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	actual_character_offset(t_data *data, size_t i)
{
	return (data -> user_input -> input[data -> user_input -> cursor + i]);
}
