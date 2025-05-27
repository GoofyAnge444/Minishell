/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:36 by eazard            #+#    #+#             */
/*   Updated: 2025/05/27 17:34:21 by eazard           ###   ########.fr       */
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

int heredoc(t_data *data, char *delimiter, bool	expend_env_var)
{
	int		fd;
	char	*line;
	//rajouter un fork, si jamais le child est kill, on recupere son status de sortie, si il a ete kill, on le met dans une variable dans la data
	// si jamais l'open dans le heredoc fail, on exit en mode failure error tt ca.
	fd = open(".heredoc_tmp", O_TRUNC | O_WRONLY | O_CREAT,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (fd == -1)
		return (fd);
	while (true)
	{
		line = NULL;
		rl_catch_signals = 0;
		set_signals_heredoc(); // TODO : declanche une non fatale error!
		line = readline(">");
		set_signals_noninteractive();
		if (SIGINT_HEREDOC == catch_last_signal())
		{
			if (line)
				free(line);
			restore_stdin();        // Indique une nouvelle ligne
			return (non_fatal_error_clean(data, HEREDOC_SIGNAL_INTERUPTION),
				-2);
		}
		if (!line || ft_strcmp(line, delimiter) == true)
			break ;
		if (expend_env_var)
			heredoc_expend_line(data, &line);
		ft_printf_fd(fd, "%s\n", line);
		free(line);
	}
	if (line)
		free(line);
	else
		heredoc_warning_message(delimiter);
	close(fd);
	return (0);
}
