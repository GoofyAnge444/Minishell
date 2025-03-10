/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_segment_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:35:55 by eazard            #+#    #+#             */
/*   Updated: 2025/03/08 19:47:15 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_segment_content(t_segment_content *segment_content)
{
	if (segment_content)
	{
		if (segment_content -> cmd_name)
		{
			free(segment_content -> cmd_name);
			segment_content -> cmd_name = NULL;
		}
		if (segment_content -> cmd_args)
		{
			ft_free_tab(segment_content -> cmd_args);
			segment_content -> cmd_args = NULL;
		}
		if (segment_content -> redir_tab)
		{
			free_redir_tab(segment_content -> redir_tab);
			segment_content -> redir_tab = NULL;
		}
		free(segment_content);
	}
}
