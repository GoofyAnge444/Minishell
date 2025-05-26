/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:22:21 by eazard            #+#    #+#             */
/*   Updated: 2025/05/26 19:54:12 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_signal.h"

static void	signal_reset_prompt(int singal)
{
	(void)singal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	ignore_sigquit(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

static void	signal_print_newline(int signal)
{
	if (SIGQUIT == signal)
		ft_printf("Quit\n");
	rl_on_new_line();
}

void	set_signals_interactive(void)
{
	t_sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}

// void	set_signals_interactive_heredoc(t_data *data)
// {
// 	t_sigaction	act;

// 	ignore_sigquit();
// 	ft_memset(&act, 0, sizeof(act));
// 	act.sa_handler = &non_fatal_error_clean;
// 	sigaction(SIGINT, &act, NULL);
// }

void	set_signals_noninteractive(void)
{
	t_sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}


