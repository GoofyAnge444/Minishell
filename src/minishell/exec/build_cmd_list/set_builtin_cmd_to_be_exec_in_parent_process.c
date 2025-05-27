/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_builtin_cmd_to_be_exec_in_parent_process        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:54:49 by eazard            #+#    #+#             */
/*   Updated: 2025/05/26 18:11:17 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
DOIT ON EXECUTER CES COMMANDES DANS LE PROCESS PARENT ?

 Your shell must implement the following built-in commands:
◦ echo with option -n NO
◦ cd with only a relative or absolute path YES
◦ pwd with no options NO
◦ export with no options YES si y'a plusieurs arguments
◦ unset with no options YES
◦ env with no options or arguments NO
◦ exit with no options YES
*/
static bool	cmd_should_be_exec_in_parent_process(t_cmd_content	*content)
{
	if (content -> cmd_name && false == content -> skip_cmd)
	{
		if (true == ft_strcmp(content->cmd_name, "cd"))
			content -> exec_cmd_in_parent_process = true;
		else if (true == ft_strcmp(content->cmd_name, "export")
			&& ft_tablen(content->cmd_args) > 1)
			content -> exec_cmd_in_parent_process = true;
		else if (true == ft_strcmp(content->cmd_name, "unset"))
			content -> exec_cmd_in_parent_process = true;
		else if (true == ft_strcmp(content->cmd_name, "exit"))
			content -> exec_cmd_in_parent_process = true;
	}
	return (false);

}

static void	set_cmd_to_be_exec_in_parent_process(t_cmd_content	*content)
{
	content -> exec_cmd_in_parent_process = true;
}

void	set_builtin_cmd_to_be_exec_in_parent_process(t_data *data,
			t_dll_list *cmd_dll)
{
	t_dll_node	*cmd;

	(void)data;
	cmd = cmd_dll->head;
	while (cmd)
	{
		if (cmd_should_be_exec_in_parent_process(cmd->content))
			set_cmd_to_be_exec_in_parent_process(cmd->content);
		cmd = cmd -> next;
	}
}
