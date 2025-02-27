/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:53:34 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:00:29 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_command_content(t_command_content *content)
{
	ft_printf("cmd_name : %s\n", content -> name);
	ft_print_tab("cmd_arg", content -> args);
	ft_printf("cmd_redir adress : %p\n", content -> redir);
}
