/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:26:06 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/04 16:31:28 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_env_content(t_env_content *env_content)
{
	if (env_content)
	{
		if (env_content -> name)
			free(env_content -> name);
		if (env_content -> value)
			free(env_content -> value);
		free(env_content);
	}
}

