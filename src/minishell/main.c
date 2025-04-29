/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 17:31:35 by eazard           ###   ########.fr       */
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

static void	print_file(char *filename)
{
	int		fd;
	char	*line;

	ft_printf("\n\n\n~~~%s~~~\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf_fd(2, "%s open error\n", filename);
		return ;
	}
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s", line);
		free(line);
		line = NULL;
	}
	close (fd);
	ft_printf("~~~~~~~~~~~~~~~~~~\n\n", filename);
}

static void	print_result_for_dev(t_data *data)
{
	dll_print_list(data ->lexer->linked_token,
		(void (*)(void *))(&print_token_content));
	ft_printf("\n\n\n");
	dll_print_list(data -> parsing -> segment_dll,
		(void (*)(void *))(&print_segment_content));
	ft_printf("\n\n");
	dll_print_list(data -> exec -> cmd_dll,
		(void (*)(void *))(&print_cmd_content));
	if (access(".heredoc_tmp", F_OK) == 0)
		print_file(".heredoc_tmp");
}

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
			print_result_for_dev(&data); // a retirer plus tard
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
