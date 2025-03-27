/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:30:40 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/27 19:53:04 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_segment_content *content, t_data *data)
{
	(void)data;
	if (!ft_strcmp(content->cmd_name, "echo"))
		return (ft_echo(content, 0), 0);
	else if (!ft_strcmp(content->cmd_name, "pwd"))
		return (ft_pwd(), 0);
	/* if (!ft_strcmp(content->cmd_name, "cd"))
		return (ft_cd(content->cmd_args, data));
	else if (!ft_strcmp(content->cmd_name, "echo"))
		return (ft_echo(content->cmd_args, 0));
	else if (!ft_strcmp(content->cmd_name, "export"))
		return (ft_export(content->cmd_args, data));
	else if (!ft_strcmp(content->cmd_name, "unset"))
		return (ft_unset(content->cmd_args, data), 0);
	else if (!ft_strcmp(content->cmd_name, "env"))
		return (ft_env(data), 0);
	else if (!ft_strcmp(content->cmd_name, "exit"))
		return (ft_exit(content->)); */
	return (1);
}

void	exec(t_data *data, t_dll_list *lst)
{
	if (exec_builtin(lst->head->content, data) == 1)
		ft_printf("execve\n");
//    while(liste token pas fini)
//        if(token command)
//		        if (!builtins)
//		            getenv()
//		            fork(); //sinon le prog s'arrêtera;
//		          //jsp si on fork avec les builtins, pas nécesaire?
//		            if(argument)
//	                action spé qui inclut;
//		            execve(command);
}
