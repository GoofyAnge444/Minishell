/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:01:22 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/11 16:01:55 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_token_content(t_token_content *token_content)
{
	if (token_content)
	{
		if (token_content -> value)
			free(token_content -> value);
		free(token_content);
	}
}
