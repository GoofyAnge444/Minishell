/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:27:39 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 22:00:33 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	next_character(t_data *data)
{
	return (data -> user_input -> input[data -> user_input -> cursor + 1]);
}
