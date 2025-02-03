/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:23:05 by eazard            #+#    #+#             */
/*   Updated: 2025/02/03 17:23:53 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	bypass(int ac, char *av[], char *env[])
{
	(void)ac;
	(void)av;
	(void)env;
}

static void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[], char *env[])
{
	t_dll_list	*list;
	t_dll_node	*node;
	t_dll_node	*node_found;
	char		*line;

	bypass(ac, av, env);
	list = dll_new_list();
	if (!list)
		return (EXIT_FAILURE);
	line = get_next_line(0);
	while (line)
	{
		node = dll_new_node((void *)line);
		if (!node)
			return (free(line), dll_clear_list(list, &free), EXIT_FAILURE);
		dll_insert_tail(list, node);
		line = get_next_line(0);
	}
	dll_print_list(list, (void (*)(void *))&ft_putstr);
	node_found = dll_find_node(list, "hello\n", (bool (*)(void *, void *))&ft_strcmp);
	if (node_found)
		ft_printf("on a trouve %s\n", node_found -> content);
	else
		ft_printf("no node found\n");
	ft_printf("list len = %i\n", (int)dll_len(list));
	if (line)
		free(line);
	dll_clear_list(list, &free);
	return (0);
}
