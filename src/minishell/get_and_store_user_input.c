/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_store_user_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:25 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/27 18:20:26 by eazard           ###   ########.fr       */
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
	// rl_clear_history();
	// rl_on_new_line();
	// rl_replace_line("", 0);
	input = readline("mishell$ ");
	// input = readline("minishell-1.0$ ");
	set_signals_noninteractive();
	//input = get_user_input(NPRINT "ꩇׁׅ݊ꪱׁׅ ꩇׁׅ݊ꪱׁׅ꯱ׁׅ֒hׁׅ֮ꫀׁׅܻᥣׁׅ֪ᥣׁׅ֪ ⋆｡‧˚ʚ🍓ɞ˚‧｡⋆ ~~>" RPRINT);
	if (!input)
	{
		ft_printf("exit\n");
		fatal_error_clean_exit(data, NOTHING);
	}
	add_history(input);
	store_user_input_in_data(data, input);
	init_cursor_at_zero(data);
}

// if user_input != 0 && !*user_input,  add_history(data)
