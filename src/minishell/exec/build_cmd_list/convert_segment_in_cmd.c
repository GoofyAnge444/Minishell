/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_segment_in_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:46 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 14:46:58 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**ft_tabdup(char **tab)
{
	size_t	i;
	char	**new_tab;

	new_tab = NULL;
	if (tab)
	{
		i = 0;
		while (tab[i])
			i++;
		new_tab = ft_calloc(i + 1, sizeof(char *));
		if (!new_tab)
			return (NULL);
		i = 0;
		while (tab[i])
		{
			new_tab[i] = ft_strdup(tab[i]);
			if (!new_tab[i])
				return (ft_free_tab(new_tab), NULL);
			i++;
		}
	}
	return (new_tab);
}

static void	init_cmd_content(t_cmd_content *cmd_content)
{
	cmd_content->fd_in = -2;
	cmd_content->fd_out = -2;
}

t_cmd_content	*convert_segment_in_cmd(t_data *data,
					t_segment_content *segment)
{
	t_cmd_content	*cmd_content;

	cmd_content = ft_calloc(1, sizeof(t_cmd_content));
	if (!cmd_content)
		return (NULL);
	data -> exec -> tmp__cmd_content = cmd_content;
	init_cmd_content(cmd_content);
	if (segment -> cmd_name)
	{
		cmd_content -> cmd_name = ft_strdup(segment -> cmd_name);
		if (!cmd_content -> cmd_name)
			return (free_cmd_content(cmd_content), NULL);
		cmd_content -> cmd_args = ft_tabdup(segment -> cmd_args);
		if (!cmd_content -> cmd_args)
			return (free_cmd_content(cmd_content), NULL);
	}
	data -> exec -> tmp__cmd_content = NULL;
	return (cmd_content);
}
