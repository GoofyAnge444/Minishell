/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:36 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:55:16 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	heredoc_warning_message(char *delimiter)
{
	ft_printf("bash: warning: here-document");
	ft_printf(" delimited by end-of-file (wanted `%s')\n", delimiter);
}

static void	heredoc_expend_line(t_data *data, char **line)
{
	char	*expended_line;

	data -> exec -> tmp__heredoc_line = *line;
	expended_line = expend_value(data, *line);
	if (!expended_line)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	free (*line);
	*line = expended_line;
	data -> exec -> tmp__heredoc_line = NULL;
}

static void	restore_stdin(void)
{
	int	tty_fd;

	tty_fd = open ("/dev/tty", O_RDONLY);
	if (-1 != tty_fd)
	{
		dup2(tty_fd, STDIN_FILENO);
		close(tty_fd);
	}
}

static int	heredoc_loop(t_data *data, char *delimiter,
				bool expend_env_var, t_heredoc_data *heredoc_data)
{
	while (true)
	{
		heredoc_data->line = NULL;
		set_signals_heredoc();
		heredoc_data->line = readline(">");
		set_signals_noninteractive();
		if (SIGINT_HEREDOC == catch_last_signal())
		{
			if (heredoc_data->line)
				free(heredoc_data->line);
			restore_stdin();
			ft_printf(" \n");
			return (non_fatal_error_clean(data, HEREDOC_SIGNAL_INTERUPTION),
				-2);
		}
		if (!heredoc_data->line
			|| ft_strcmp(heredoc_data->line, delimiter) == true)
			break ;
		if (expend_env_var)
			heredoc_expend_line(data, &heredoc_data->line);
		ft_printf_fd(heredoc_data->fd, "%s\n", heredoc_data->line);
		free(heredoc_data->line);
	}
	return (0);
}

int	heredoc(t_data *data, char *delimiter, bool	expend_env_var)
{
	t_heredoc_data	heredoc_data;

	heredoc_data.fd = open(".heredoc_tmp", O_TRUNC | O_WRONLY | O_CREAT,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (heredoc_data.fd == -1)
		return (heredoc_data.fd);
	if (-2 == heredoc_loop(data, delimiter, expend_env_var, &heredoc_data))
		return (-2);
	if (heredoc_data.line)
		free(heredoc_data.line);
	else
		heredoc_warning_message(delimiter);
	close(heredoc_data.fd);
	return (0);
}
