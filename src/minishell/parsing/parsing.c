/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:46:42 by eazard            #+#    #+#             */
/*   Updated: 2025/02/27 12:35:19 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	count_cmd_nb(t_data *data)
{
	t_dll_node	*node;
	int			cmd_count;

	cmd_count = 0;
	node = data -> lexer -> linked_token -> head;
	while (node)
	{
		if (is_a_cmd_token(node))
			cmd_count++;
		node = node -> next;
	}
	return (cmd_count);
}

void	parsing(t_data *data)
{
	int	cmd_count;
	int	processed_cmd_index;

	create_parsing_space(data);
	cmd_count = count_cmd_nb(data);
	ft_printf("cmd_count = %i\n", cmd_count);
	processed_cmd_index = 0;
	while (processed_cmd_index < cmd_count)
	{
		add_next_command_node_to_parsing(data, processed_cmd_index);
		processed_cmd_index++;
	}
}


/* 

ꩇׁׅ݊ꪱׁׅ ꩇׁׅ݊ꪱׁׅ꯱ׁׅ֒hׁׅ֮ꫀׁׅܻᥣׁׅ֪ᥣׁׅ֪ ⋆｡‧˚ʚ🍓ɞ˚‧｡⋆ ~~>ceci est un test | suivi d'un' deuxieme < test
cmd_count = 2
malloc(): memory corruption (fast)
[1]    78569 IOT instruction  ./minishell

faut gerer ca ?? force a toi chef

*/