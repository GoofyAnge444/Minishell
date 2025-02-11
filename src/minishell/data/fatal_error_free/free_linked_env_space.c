/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_linked_env_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:47:26 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/10 18:20:54 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_linked_env_space(t_data *data)
{
	dll_clear_list(data -> env, (void (*)(void *))(&free_env_content));
}
