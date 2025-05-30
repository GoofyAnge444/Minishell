/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:02:32 by eazard            #+#    #+#             */
/*   Updated: 2025/05/01 14:59:13 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	print_cmd_content(t_cmd_content *cmd_content)
{
	ft_printf("\n\n~~~~CMD~~~~\n");
	ft_printf("___CMD_NAME___\n");
	ft_printf("%s\n", cmd_content -> cmd_name);
	ft_printf("\n___CMD_ARGS___\n");
	ft_print_tab("cmd_arg", cmd_content -> cmd_args);
	ft_printf("\n___FD_IN___\n");
	ft_printf("%i\n", cmd_content -> fd_in);
	ft_printf("\n___FD_OUT___\n");
	ft_printf("%i\n", cmd_content -> fd_out);
	ft_printf("\n___SKIP_CMD___\n");
	if (cmd_content ->skip_cmd)
		ft_printf("true\n");
	else
		ft_printf("false\n");
}
