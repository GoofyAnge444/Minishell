/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:26:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 17:21:18 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	actual_character(t_data *data)
{
	// ft_printf("cursor value %i\n", (int)(data -> user_input -> cursor));
	return (data -> user_input -> input[data -> user_input -> cursor]);
}
