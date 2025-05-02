/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:21:41 by eazard            #+#    #+#             */
/*   Updated: 2025/05/02 13:25:23 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
set_all_pipe - pseudo_code
SI
parcours la liste de command, pour chaque command effectue une pipe si :
cette command n'a aucun fd_out (fd_out vaut alors -2)
OU
la prochaine commande existe ET elle n'a aucun fd_in (fd_in vaut alors -2)
ALORS
	{
	SI cette command n'a aucun fd_out (fd_out vaut alors -2)
		ALORS
			on va dup le pipe[1] vers le fdout;
	close le pipe [1]
	SI la prochaine commande existe ET elle n'a aucun fd_in (fd_in vaut alors -2)
		ALORS
		on va dup le pipe[0] vers le fdin de la prochaine commande;
	close le pipe [0];
	
	}

SINON
	rien;
*/


void	set_all_pipe(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node	*cmd;

	cmd = cmd_dll->head;
	while (cmd)
	{
		set_pipe_in_a_cmd(data, cmd);
		cmd = cmd->next;
	}
}
