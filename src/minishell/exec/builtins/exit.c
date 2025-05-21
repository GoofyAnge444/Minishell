/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:23 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/21 18:21:16 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_exit(t_data *data)
{
	free_data(data, true);
}

void	ft_exit(t_cmd_content *content, t_data *data)
{
	int		code;
	char	**str;

	str = content->cmd_args;
	if (str[1])
	{
		if (!ft_isnumber(str[1]))
		{
			ft_printf_fd(2,
				"exit\nmimishell: exit: %s: numeric argument required\n",
				str[1]);
			exit(2);
		}
		if (str[2])
			ft_printf_fd(2,
				"exit\nmimishell: exit: too many arguments");
		else
		{
			code = ft_atoi(str[1]);
			exit((code) % 256);
		}
	}
	free_exit(data);
	exit(0);
}
