/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:41 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:14:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_lexer_space(t_data *data)
{
	if (data && data -> lexer)
	{
		if (data -> lexer -> linked_token)
		{
			dll_clear_list(data -> lexer -> linked_token,
				(void (*)(void *))(&free_token_content));
		}
		free(data -> lexer);
	}
}
