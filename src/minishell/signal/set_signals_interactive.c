/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals_interactive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:52:38 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 17:03:38 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_signal.h"

static void	signal_reset_prompt(int singal)
{
	(void)singal;
	g_signal = SIGINT_INTERACTIVE;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_signals_interactive(void)
{
	t_sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_reset_prompt;
	sigaction(SIGINT, &act, NULL);
}
