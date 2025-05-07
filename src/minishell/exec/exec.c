/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:30:40 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/01 01:28:11 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec_builtin(t_segment_content *content, t_data *data)
{
	(void)data;
	if (!ft_strcmp(content->cmd_name, "echo"))
		return (ft_echo(content), 0);
	else if (!ft_strcmp(content->cmd_name, "pwd"))
		return (ft_pwd(), 0);
	else if (!ft_strcmp(content->cmd_name, "env"))
		return (ft_env(data), 0);
	else if (!ft_strcmp(content->cmd_name, "unset"))
		return (ft_unset(content, data), 0);
	else if (!ft_strcmp(content->cmd_name, "exit"))
		return (ft_exit(content), 0);
	/* else if (!ft_strcmp(content->cmd_name, "cd"))
		return (ft_cd(content, data));
	else if (!ft_strcmp(content->cmd_name, "export"))
		return (ft_export(content, data), 0);*/
	return (1);
}

void	exec(t_data *data, t_dll_list *seg_lst)
{
	if (exec_builtin(seg_lst->head->content, data) == 1)
		ft_printf("execve\n");
		// utilser gnl est compliqué pour : -historique (addHistory existe pour readline)
				//execve apparement, le prompt réapparaitrait pas (i'll tell u about that)
				//jean a un tshirt tancended, personne n'a fini le projet avec gnl mdr
				//gestion signal et gestion de redir avec les fd. Possible a faire mais la structure ressemblerait à readline.
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
