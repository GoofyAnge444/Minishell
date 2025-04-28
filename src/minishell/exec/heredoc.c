/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:42:36 by eazard            #+#    #+#             */
/*   Updated: 2025/04/28 18:58:21 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	heredoc(char *delimiter)
{
	int		fd;
	char	*line;

	fd = open(".heredoc_tmp", O_TRUNC | O_WRONLY | O_CREAT,
			BASH_POSIX_CREATED_FILE_WRITE_COPY);
	if (fd == -1)
		return (fd);
	line = readline(">");
	if (!line)
		;// TODO
	while (line && !ft_strcmp(line, delimiter))
	{	
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(">");
		if (!line)
			;//TODO
	}
	if (line) // PEUT ETRE ON POURRA DELETE CE CHECK
		free(line);
	close(fd);
	return (open(".heredoc_tmp", O_RDONLY)); // TODO rajouter un if (access) then unset() dans la fonction free_data
}
