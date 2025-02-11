/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:26:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:30:31 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	actual_character(t_data *data)
{
	ft_printf("actual_character IN\n");
	return (data -> user_input -> input[data -> user_input -> cursor]);
}
