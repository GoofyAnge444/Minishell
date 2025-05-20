/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:04:49 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/20 17:35:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char *env[])
{
	ft_memset(data, 0, sizeof(t_data));
	create_lexer_space(data);
	create_user_input_space(data);
	create_linked_env_space(data);
	created_linked_env(data, env);
	create_export_space(data);
	create_parsing_space(data);
	// create_fatal_error_space(data);
}
