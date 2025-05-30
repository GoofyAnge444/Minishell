/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_store_user_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:25 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/30 16:59:40 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_user_input(char *prompt)
{
	ft_printf("%s", prompt);
	return (get_next_line(0));
}

static void	store_user_input_in_data(t_data *data, char *input)
{
	data -> user_input -> input = input;
}

static void	init_cursor_at_zero(t_data *data)
{
	data -> user_input -> cursor = 0;
}

void	get_and_store_user_input(t_data *data)
{
	char			*input;

	set_signals_interactive();
	input = readline("mishell$ ");
	set_signals_noninteractive();
	if (catch_last_signal() == SIGINT_INTERACTIVE)
	{
		ft_printf_fd(2, "signal catched\n");
		data -> last_exit_code = SIGINT + 128;
	}
	if (!input)
	{
		ft_printf("exit\n");
		free_data(data, true);
		exit(data->last_exit_code);
	}
	add_history(input);
	store_user_input_in_data(data, input);
	init_cursor_at_zero(data);
}
