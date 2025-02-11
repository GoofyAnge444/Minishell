/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_heredoc_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:05 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 00:15:51 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*get_next_heredoc_value(t_data *data)
{
	moov_cursor_forward_of_one(data);
	moov_cursor_forward_of_one(data);
	return ("<<");
}
