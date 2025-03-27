/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:47:46 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/27 19:22:39 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_echo(t_segment_content *content, t_data *data)
{
	int	i;
	(void)data;
	i = 1;
	//printf("echo\n");·
	if (have_n(content->cmd_args[i]) == 0)
	{
		//printf("have n\n");
		i++;
	}
	//printf("%s", content->cmd_args[i]);
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
