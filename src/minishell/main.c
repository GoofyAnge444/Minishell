/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/26 15:36:56 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	bypass(int ac, char *av[], char *env[])
// {
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// }
// static void    print_content(t_env_content *env_content)
// {
// 	ft_printf("content = %s\n", env_content -> name);
// 	ft_printf("value = %s\n", env_content -> value);
// }



int	main(int ac, char *av[], char *env[])
{
	t_data			data;

	(void)ac;
	(void)av;
	init_data(&data, env);
	while (1)
	{
		data.non_fatal_error_occured = false;
		get_and_store_user_input(&data);
		lexer(&data);
		if (data.non_fatal_error_occured == false)
		{
			dll_print_list(data.lexer->linked_token,
				(void (*)(void *))(&print_token_content));
			free_data(&data, 0);
		}
	}
	return (0);
}

// int	main(int ac, char *av[], char *env[])
// {
// 	t_binary_tree	*binary_tree;

// 	bypass(ac, av, env);
// 	char *str = ft_strdup("Hello World!\n");
// 	binary_tree = join_binary_tree(NULL, NULL, str);
// 	if (!binary_tree)
// 		return (1);
// 	clear_binary_tree(binary_tree, &free);
// 	return (0);
// }
