/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_segment_in_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:46 by eazard            #+#    #+#             */
/*   Updated: 2025/04/27 19:10:13 by eazard           ###   ########.fr       */
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

t_cmd_content	*convert_segment_in_cmd(t_segment_content *segment) //free_cmd_content TODO
{
	t_cmd_content	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd_content));
	if (!cmd)
		return (NULL);
	cmd -> cmd_name = ft_strdup(segment -> cmd_name); // TODO : check success, free if failure
	cmd -> cmd_name = ft_tabdup(segment -> cmd_args); // TODO : check success, free if failure
	// get infile
	// get outfile
}