/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:56:07 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/01 00:55:27 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*get_hd_input(void)
{
	ft_putstr_fd("~~>", 1);
	return (get_next_line(0));
}

void	heredoc_manager(t_data *data, t_redir *redir)
{
	int		fd_infile;
	char	*line;

	fd_infile = open("heredoc.txt"); //contient le fd/tuyaux ou on va envoyer les inputs
	while (1)
	{
		line = get_hd_input();
		if (ft_strcmp(redir->filename, line) == 0)
			break ;
		write(fd_infile, line, ft_strlen(line));
	}
	dup2(fd_infile, 1);
}
