/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/05/06 17:00:44 by eazard           ###   ########.fr       */
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

int g_last_exit_code = 0;

static bool	empty_input_check(t_data *data)
{
	return (data -> user_input->input[0] == '\0');
}

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
		if (empty_input_check(&data) == false)
		{
			lexer(&data);
			parsing(&data);
			exec(&data);
		}
		if (data.non_fatal_error_occured == false)
		{
			// print_result_for_dev(&data); // a retirer plus tard
			free_data(&data, false);
		}
	}
	return (0);
}

// int	main(int ac, char *av[], char *env[])
// {
// 	char *line;

// 	bypass(ac, av, env);
// 	line = readline("enter a prompt:\n");
// 	if (line)
// 	{
// 		ft_printf("line is --->%s<---\n", line);
// 		free(line);
// 		ft_printf("line is free\n");
// 	}
// 	else
// 		ft_printf("line is NULL\n");
// 	rl_on_new_line ();
// 	rl_clear_history();
// 	return (0);
// }
