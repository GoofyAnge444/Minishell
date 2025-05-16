/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:00 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/15 17:31:37 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data(t_data *data, bool fatal)
{
	if (data)
	{
		free_user_input_space(data, fatal);
		free_lexer_space(data, fatal);
		free_linked_env_space(data, fatal);
		free_export_space(data, fatal); //we try
		free_parsing_space(data, fatal);
		// free_fatal_error_space(data, fatal);
	}
}
