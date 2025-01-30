/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/01/30 16:27:12 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bypass(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	(void)env;
}

int	main(int ac, char *av[], char *env[])
{
	bypass(ac, av, env);
	ft_printf("HELLO WORLD\n");
	return (0);
}
