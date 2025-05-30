/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:53:55 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 15:00:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SIGNAL_H
# define MY_SIGNAL_H
# include "minishell.h"

typedef struct sigaction	t_sigaction;

void			set_signals_noninteractive(void);
void			set_signals_interactive(void);
void			set_signals_heredoc(void);
int				catch_last_signal(void);
void			ignore_sigquit(void);

#endif
