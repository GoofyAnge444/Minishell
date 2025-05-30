/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 16:53:34 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal = NO_SIG_TO_CATCH;

static bool	empty_input_check(t_data *data)
{
	return (data -> user_input->input[0] == '\0');
}

int	main(int ac, char *av[], char *env[])
{
	t_data			data;

	(void)ac;
	(void)av;
	init_data(&data, env);
	while (1)
	{
		data.non_fatal_error_occured = false;
		get_and_store_user_input(&data);
		if (empty_input_check(&data) == false)
		{
			lexer(&data);
			parsing(&data);
			exec(&data);
		}
		if (data.non_fatal_error_occured == false)
		{
			free_data(&data, false);
		}
	}
	return (0);
}
