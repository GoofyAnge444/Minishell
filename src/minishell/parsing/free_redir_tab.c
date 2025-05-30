/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:09:08 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 17:15:57 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_redir_tab(t_redir **redir_tab)
{
	int	i;

	i = 0;
	while (redir_tab[i])
	{
		if (redir_tab[i] && redir_tab[i]-> filename)
			free(redir_tab[i]-> filename);
		if (redir_tab[i])
			free(redir_tab[i]);
		i++;
	}
	free(redir_tab);
}
