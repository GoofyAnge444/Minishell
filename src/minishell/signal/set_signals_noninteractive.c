/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals_noninteractive.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:54:59 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 14:56:36 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_signal.h"

static void	signal_print_newline(int signal)
{
	if (SIGQUIT == signal)
		ft_printf("Quit\n");
	rl_on_new_line();
}

void	set_signals_noninteractive(void)
{
	t_sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_print_newline;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
