/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/11 17:11:39 by eazard           ###   ########.fr       */
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
	// ft_printf("content = %s\n", env_content -> name);
	// ft_printf("value = %s\n", env_content -> value);
// }



int	main(int ac, char *av[], char *env[])
{
	t_data			data;

	(void)ac;
	(void)av;
	init_data(&data, env);
	while (1)
	{
		get_and_store_user_input(&data);
		lexer_state_machine(&data);
		dll_print_list(data.lexer->linked_token,
			(void (*)(void *))(&print_token_content));
		fatal_error_clean_exit(&data, MALLOC_FAILURE);
	}
	return (0);
}

