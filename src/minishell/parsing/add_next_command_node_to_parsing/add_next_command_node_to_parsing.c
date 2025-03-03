/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_command_node_to_parsing.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:42:16 by eazard            #+#    #+#             */
/*   Updated: 2025/03/03 17:41:22 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_next_command_node_to_parsing(t_data *data, int processed_cmd_index)
{
	t_command_content	*command_content;
	t_dll_node			*node;

	command_content = ft_calloc(1, sizeof(t_command_content));
	if (!command_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	add_cmd_name(data, command_content, processed_cmd_index);
	add_cmd_arg(data, command_content, processed_cmd_index);
	add_cmd_redir(data, command_content, processed_cmd_index);
	node = dll_new_node((void *)command_content);
	if (!node)
		return (free_command_content(command_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	dll_insert_tail(data -> parsing_commands, node);
}


/* 

ꩇׁׅ݊ꪱׁׅ ꩇׁׅ݊ꪱׁׅ꯱ׁׅ֒hׁׅ֮ꫀׁׅܻᥣׁׅ֪ᥣׁׅ֪ ⋆｡‧˚ʚ🍓ɞ˚‧｡⋆ ~~>ceci est un test | suivi d'un' deuxieme < test
cmd_count = 2
malloc(): memory corruption (fast)
[1]    78569 IOT instruction  ./minishell

faut gerer ca ?? force a toi chef

deuxieme test ʚ🍓ɞ: ~~>ceci est un test | < test | que passo cono | bonne < question bg
*/