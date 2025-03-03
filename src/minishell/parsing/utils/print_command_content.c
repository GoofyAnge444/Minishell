/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:53:34 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 17:51:23 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_printf_redir_ptr_tab(t_redir **redir_ptr_tab)
{
	int	i;

	i = 0;
	ft_printf("\n___REDIR_TAB___\n");
	if (redir_ptr_tab)
	{
		while (redir_ptr_tab[i])
		{
			ft_printf("redir %i\ntype :", i);
			print_token_type(redir_ptr_tab[i]-> redir_type);
			ft_printf("filename : %s\n", redir_ptr_tab[i]-> filename);
			i++;
		}
	}
	else
		ft_printf("redir_tab_ptr is (null)\n");
}

void	print_command_content(t_command_content *content)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\n");
	ft_printf("___CMD_NAME___\n");
	ft_printf("%s\n", content -> name);
	ft_printf("\n___CMD_ARGS___\n");
	ft_print_tab("cmd_arg", content -> args);
	ft_printf_redir_ptr_tab(content -> redir);
	ft_printf("~~~~~~~~~~~~~~\n");
}
