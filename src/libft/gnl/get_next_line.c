/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:39:27 by eazard            #+#    #+#             */
/*   Updated: 2024/12/04 16:29:31 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fill_buffer(char *buffer, int fd)
{
	int	read_output;

	if (ft_is_buffer_empty(buffer))
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)
			return (BUFFER_EMPTY_BC_READ_FAILURE);
		else if (read_output == 0)
			return (BUFFER_EMPTY_BC_END_OF_FILE);
		else
			return (BUFFER_NON_EMPTY);
	}
	else
		return (BUFFER_NON_EMPTY);
}

int	ft_destroy_and_create_line(char **line, char *buffer)
{
	size_t	i;
	char	*new;
	char	*old;

	if ((*line) == NULL)
	{
		(*line) = ft_calloc(ft_buffer_len(buffer) + 1, 1);
		if (!(*line))
			return (GNL_ERROR);
		return (GNL_SUCCESS);
	}
	new = ft_calloc(ft_buffer_len(buffer) + ft_strlen((*line)) + 1, 1);
	if (!new)
		return (free((*line)), GNL_ERROR);
	old = (*line);
	i = 0;
	while ((*line)[i])
	{
		new[i] = (*line)[i];
		i++;
	}
	*line = new;
	free(old);
	return (GNL_SUCCESS);
}

int	ft_fill_from_buffer_to_line(char *line, char *buffer)
{
	size_t	line_end;
	size_t	buffer_begin;
	size_t	i;

	line_end = 0;
	while (line[line_end])
		line_end++;
	buffer_begin = 0;
	while (buffer_begin < BUFFER_SIZE && buffer[buffer_begin] == '\0')
		buffer_begin++;
	i = 0;
	while (buffer_begin + i < BUFFER_SIZE && buffer[buffer_begin + i] != '\n'
		&& buffer[buffer_begin + i] != '\0')
	{
		line[line_end + i] = buffer[buffer_begin + i];
		buffer[buffer_begin + i] = '\0';
		i++;
	}
	if (buffer[buffer_begin + i] == '\n')
	{
		line[line_end + i] = '\n';
		buffer[buffer_begin + i] = '\0';
		return (EOL_FOUNDED);
	}
	return (EOL_NOT_FOUNDED);
}

int	getting_next_line_loop(char **line, char *buffer, int fd)
{
	int	buffer_status;

	while (1)
	{
		buffer_status = ft_fill_buffer(buffer, fd);
		if (buffer_status == BUFFER_EMPTY_BC_READ_FAILURE)
		{
			if ((*line))
				free((*line));
			return (GNL_ERROR);
		}
		else if (buffer_status == BUFFER_EMPTY_BC_END_OF_FILE)
			return (GNL_SUCCESS);
		if (ft_destroy_and_create_line(line, buffer) == GNL_ERROR)
			return (GNL_ERROR);
		if (ft_fill_from_buffer_to_line((*line), buffer) == EOL_FOUNDED)
			return (GNL_SUCCESS);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE == 0)
		return (NULL);
	line = NULL;
	if (getting_next_line_loop(&line, buffer, fd) == GNL_ERROR)
		return (NULL);
	return (line);
}
