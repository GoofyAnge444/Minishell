/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:56:51 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 17:35:43 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_signal.h"

static void	simulate_eof(void)
{
	int	dev_null;

	dev_null = open ("/dev/null", O_RDONLY);

	if (-1 != dev_null)
	{
		dup2(dev_null, STDIN_FILENO);
		close(dev_null);
	}
}

static void interupt_readline(int signal)
{
	if (signal == SIGINT)
	{
		g_signal = SIGINT_HEREDOC;
		
		// Indique à readline qu'il doit s'arrêter et retourner
		write(STDOUT_FILENO, "^C", 2);
		simulate_eof(); 
	}
}

void	set_signals_heredoc(void)
{
	t_sigaction	act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = &interupt_readline;
	sigaction(SIGINT, &act, NULL);
}
