/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:55:03 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:16:10 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	exec_fatal_free_space(t_data *data)
{
	if (data -> exec ->tmp__cmd_content)
	{	
		free(data -> exec ->tmp__cmd_content);
		data -> exec ->tmp__cmd_content = NULL;
	}
	if (data -> exec ->tmp__heredoc_line)
	{	
		free(data -> exec ->tmp__heredoc_line);
		data -> exec ->tmp__heredoc_line = NULL;
	}
	if (data -> exec -> bin_paths)
	{	
		ft_free_tab(data -> exec -> bin_paths);
		data -> exec -> bin_paths = NULL;
	}
	free(data -> exec);
	data -> exec = NULL;
}

void	exec_non_fatal_free_space(t_data *data)
{
	if (data -> exec -> cmd_dll)
	{
		dll_clear_list(data -> exec -> cmd_dll,
			(void (*)(void *))(&free_cmd_content));
		data -> exec -> cmd_dll = NULL;
	}
	if (data -> exec -> envp)
	{	
		ft_free_tab(data -> exec -> envp);
		data -> exec -> envp = NULL;
	}
	if (access(".heredoc_tmp", F_OK) == 0)
		unlink(".heredoc_tmp");
}

void	free_exec_space(t_data *data, bool fatal)
{
	if (data && data -> exec)
	{
		exec_non_fatal_free_space(data);
		if (fatal)
		{
			exec_fatal_free_space(data);
		}
	}
}
