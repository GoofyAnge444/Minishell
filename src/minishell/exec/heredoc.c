/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:36 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 16:41:42 by eazard           ###   ########.fr       */
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

int	heredoc(t_data *data, char *delimiter, bool	expend_env_var)
{
	int		fd;
	char	*line;

	fd = open(".heredoc_tmp", O_TRUNC | O_WRONLY | O_CREAT,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (fd == -1)
		return (fd);
	while (true)
	{
		line = readline(">");
		// line = get_user_input(">");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == true)
			break ;
		if (expend_env_var)
			heredoc_expend_line(data, &line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	else
		heredoc_warning_message(delimiter);
	close(fd);
	return (open(".heredoc_tmp", O_RDONLY));
}
