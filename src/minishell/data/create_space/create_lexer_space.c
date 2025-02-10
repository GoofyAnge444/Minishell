/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:08:44 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 17:24:22 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	create_lexer_space(t_data *data)
{
	data -> lexer = ft_calloc(1, sizeof(t_lexer));
	if (!data -> lexer)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
}
