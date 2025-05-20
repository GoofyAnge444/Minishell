/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/05/19 20:40:47 by cboma-ya         ###   ########.fr       */
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


// static void	print_result_for_dev(t_data *data)
// {
// 	dll_print_list(data ->lexer->linked_token,
// 		(void (*)(void *))(&print_token_content));
// 	ft_printf("\n\n\n");
// 	dll_print_list(data -> parsing -> segment_dll,
// 		(void (*)(void *))(&print_segment_content));
// }
// void	ft_test(t_segment_content *content)
// {
// 	ft_printf("cmd is %s\n", content->cmd_name);
// }

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
			exec(&data, data.parsing->segment_dll);
		}
		if (data.non_fatal_error_occured == false)
		{
			/*print_result_for_dev(&data); // a retirer plus tard*/
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
