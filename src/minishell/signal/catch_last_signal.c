/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_last_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:42:23 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 14:42:50 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_signal.h"

int	catch_last_signal(void)
{
	int	last_signal;

	last_signal = g_signal;
	g_signal = NO_SIG_TO_CATCH;
	return (last_signal);
}
