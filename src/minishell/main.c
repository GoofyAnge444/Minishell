/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/04 17:55:10 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	bypass(int ac, char *av[], char *env[])
// {
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// }

static void    print_content(t_env_content *env_content)
{
	ft_printf("content = %s\n", env_content -> name);
	ft_printf("value = %s\n", env_content -> value);
}

int	main(int ac, char *av[], char *env[])
{
	t_data			data;

	(void)ac;
	(void)av;
	init_data(&data, env);
	while (1)
	{
		get_and_store_user_input(&data);
		lexer(&data);
		// exit_clean();
	}
	return (0);
}

