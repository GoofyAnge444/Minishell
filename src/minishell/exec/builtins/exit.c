/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:34:23 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/30 15:32:48 by eazard           ###   ########.fr       */
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

static void	exit_with_arg(t_data *data, char **str)
{
	long long		code;

	if (!ft_isnumber(str[1]))
	{
		ft_printf_fd(2,
			"exit\nmishell: exit: %s: numeric argument required\n",
			str[1]);
		free_data(data, true);
		exit(2);
	}
	if (str[2])
	{
		ft_printf_fd(2,
			"exit\nmishell: exit: too many arguments\n");
		data -> last_exit_code = 1;
	}
	else
	{
		ft_printf("exit\n");
		code = ft_atoll(str[1]);
		free_data(data, true);
		exit((code) % 256);
	}
}

void	ft_exit(t_cmd_content *content, t_data *data)
{
	char	**str;
	int		last_exit_code;

	str = content->cmd_args;
	if (str[1])
	{
		exit_with_arg(data, str);
	}
	else
	{
		ft_printf("exit\n");
		last_exit_code = data -> last_exit_code;
		free_data(data, true);
		exit(last_exit_code);
	}
}
