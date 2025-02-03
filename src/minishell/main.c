/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/03 20:19:04 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	bypass(int ac, char *av[], char *env[])
// {
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// }

static void	print_content(t_env_content *env_content)
{
	ft_printf("content = %s\n", env_content -> name);
	ft_printf("value = %s\n", env_content -> value);
}

int	main(int ac, char *av[], char *env[])
{
	t_env_content	*env_content;

	(void)ac;
	(void)av;
	ft_printf("%s\n", env[0]);
	env_content = env_var_to_env_content(env[0]);
	print_content(env_content);
	free(env_content -> name);
	free(env_content -> value);
	free(env_content);
	return (0);
}
// TODO : coder un free_content
