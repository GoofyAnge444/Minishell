/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result_for_dev.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:55:38 by eazard            #+#    #+#             */
/*   Updated: 2025/05/06 16:06:56 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_file(char *filename)
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

void	print_result_for_dev(t_data *data)
{
	// dll_print_list(data ->lexer->linked_token,
	// 	(void (*)(void *))(&print_token_content));
	// ft_printf("\n\n\n");
	// dll_print_list(data -> parsing -> segment_dll,
	// 	(void (*)(void *))(&print_segment_content));
	// ft_printf("\n\n");
	// dll_print_list(data -> exec -> cmd_dll,
	// 	(void (*)(void *))(&print_cmd_content));
	// if (access(".heredoc_tmp", F_OK) == 0)
	// 	print_file(".heredoc_tmp");
	(void)data;
	ft_printf("last exit code : %i\n", g_last_exit_code);
}
