/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:46 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/30 14:21:29 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	have_n(char *str)
{
	int	j;

	j = 1;
	if (!str || str[0] != '-')
		return (1);
	while (str[j])
	{
		if (str[j] != 'n')
			return (1);
		j++;
	}
	return (0);
}

/*
executed in a child process
*/
void	ft_echo(t_cmd_content *content)
{
	int	i;

	i = 1;
	if (have_n(content->cmd_args[i]) == 0)
	{
		i++;
	}
	while (content->cmd_args[i])
	{
		ft_putstr_fd(content->cmd_args[i], 1);
		if (content -> cmd_args [i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (have_n(content->cmd_args[1]) == 1)
		ft_putstr_fd("\n", 1);
}
