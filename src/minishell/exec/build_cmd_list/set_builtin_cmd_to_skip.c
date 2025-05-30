/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_builtin_cmd_to_skip.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:50:09 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:23:01 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
/*
DOIT ON SKIP CES BUILTINS SI ILS SONT DANS UNE PIPELINE AVEC PLUSIEURS CMD ?

 Your shell must implement the following built-in commands:
◦ echo with option -n NO
◦ cd with only a relative or absolute path YES
◦ pwd with no options NO
◦ export with no options YES si y'a des args
◦ unset with no options YES
◦ env with no options or arguments NO
◦ exit with no options YES

cette fonction est execute SEULEMENT SI il y a + de une cmd dans la command list
*/
static bool	cmd_should_be_skip(t_cmd_content *content)
{
	if (content -> cmd_name)
	{
		if (true == ft_strcmp(content->cmd_name, "cd"))
			return (true);
		else if (true == ft_strcmp(content->cmd_name, "export")
			&& ft_tablen(content->cmd_args) > 1)
			return (true);
		else if (true == ft_strcmp(content->cmd_name, "unset"))
			return (true);
		else if (true == ft_strcmp(content->cmd_name, "exit"))
			return (true);
	}
	return (false);
}

static void	set_cmd_to_be_skip(t_cmd_content *content)
{
	content -> skip_cmd = true;
}

void	set_builtin_cmd_to_skip(t_data *data, t_dll_list *cmd_dll)
{
	t_dll_node	*cmd;

	(void)data;
	if (dll_len(cmd_dll) > 1)
	{
		cmd = cmd_dll->head;
		while (cmd)
		{
			if (cmd_should_be_skip(cmd->content))
				set_cmd_to_be_skip(cmd->content);
			cmd = cmd -> next;
		}
	}
}
