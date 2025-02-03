/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/03 17:31:23 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	bypass(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	(void)env;
}

int	main(int ac, char *av[], char *env[])
{
	bypass(ac, av, env);
	ft_printf("Hello World!\n");
	return (0);
}
