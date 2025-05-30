/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:04:49 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/30 17:01:05 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char *env[])
{
	g_signal = NO_SIG_TO_CATCH;
	data -> last_exit_code = 0;
	ft_memset(data, 0, sizeof(t_data));
	create_lexer_space(data);
	create_user_input_space(data);
	create_linked_env_space(data);
	created_linked_env(data, env);
	create_parsing_space(data);
	create_exec_space(data);
	create_export_space(data);
}
