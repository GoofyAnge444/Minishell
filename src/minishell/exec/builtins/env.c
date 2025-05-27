/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:47:21 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/27 18:30:06 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	print_env(t_env_content *env_content)
{
	if (env_content && env_content->value != 0)
		printf("%s=\"%s\"\n", env_content -> name, env_content -> value);
	else
		printf("%s=\n", env_content -> name);
}

void	ft_env(t_data *data)
{
	dll_print_list(data->env, (void (*)(void *))print_env);
}
