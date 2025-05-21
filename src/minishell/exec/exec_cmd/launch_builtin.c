/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:07:21 by eazard            #+#    #+#             */
/*   Updated: 2025/05/21 18:33:48 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	launch_builtin(t_cmd_content *content, t_data *data)
{
	(void)data;
	if (ft_strcmp(content->cmd_name, "echo"))
		ft_echo(content);
	else if (ft_strcmp(content->cmd_name, "pwd"))
		ft_pwd();
	else if (ft_strcmp(content->cmd_name, "env"))
		ft_env(data);
	else if (ft_strcmp(content->cmd_name, "unset"))
		ft_unset(content, data);
	else if (ft_strcmp(content->cmd_name, "cd"))
		ft_cd(content, data);
	else if (ft_strcmp(content->cmd_name, "export"))
		ft_export(content, data);
	else
		return (-1);
	/*else if (ft_strcmp(content->cmd_name, "exit"))
		ft_exit(content), 0);
	;
		ne fonctionnent pas en pipe ?? 
	*/
	free_data(data, true);
	exit(0);
}
