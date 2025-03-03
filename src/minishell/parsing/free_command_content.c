/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:35:55 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 17:08:51 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_command_content(t_command_content *command_content)
{
	if (command_content)
	{
		if (command_content -> name)
		{
			free(command_content ->name);
			command_content ->name = NULL;
		}
		if (command_content -> args)
		{
			ft_free_tab(command_content -> args);
			command_content -> args = NULL;
		}
		if (command_content -> redir)
		{
			free_redir_tab(command_content -> redir);
			command_content -> redir = NULL;
		}
		free(command_content);
	}
}
