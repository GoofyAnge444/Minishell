/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:41 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/18 15:43:43 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_lexer_space(t_data *data, bool fatal)
{
	if (data && data -> lexer)
	{
		if (data -> lexer -> linked_token)
		{
			dll_clear_list(data -> lexer -> linked_token,
				(void (*)(void *))(&free_token_content));
			data -> lexer -> linked_token = NULL;
		}
		if (fatal)
		{
			free(data -> lexer);
			(data -> lexer) = NULL;
		}
	}
}
