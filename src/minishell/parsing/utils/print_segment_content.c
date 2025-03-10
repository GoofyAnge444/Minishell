/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_segment_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:53:34 by eazard            #+#    #+#             */
/*   Updated: 2025/03/08 19:50:01 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_printf_redir_ptr_tab(t_redir **redir_tab)
{
	int	i;

	i = 0;
	ft_printf("\n___REDIR_TAB___\n");
	if (redir_tab)
	{
		while (redir_tab[i])
		{
			ft_printf("redir %i\ntype :", i);
			print_token_type(redir_tab[i]-> redir_type);
			ft_printf("filename : %s\n", redir_tab[i]-> filename);
			i++;
		}
	}
	else
		ft_printf("redir_tab_ptr is (null)\n");
}

void	print_segment_content(t_segment_content *segment_content)
{
	ft_printf("\n\n~~~~SEGMENT~~~~\n");
	ft_printf("___CMD_NAME___\n");
	ft_printf("%s\n", segment_content -> cmd_name);
	ft_printf("\n___CMD_ARGS___\n");
	ft_print_tab("cmd_arg", segment_content -> cmd_args);
	ft_printf_redir_ptr_tab(segment_content -> redir_tab);
	ft_printf("~~~~~~~~~~~~~~~\n");
}
