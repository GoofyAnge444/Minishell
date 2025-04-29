/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:25:00 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/04/29 17:33:06 by eazard           ###   ########.fr       */
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
		free_parsing_space(data, fatal);
		free_exec_space(data, fatal);
		if (fatal)
			rl_clear_history();
	}
}
