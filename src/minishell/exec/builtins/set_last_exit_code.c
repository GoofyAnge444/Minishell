/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_exit_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:27:01 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 18:27:24 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	set_last_exit_code(t_data *data, int last_exit_code)
{
	data -> last_exit_code = last_exit_code;
}
