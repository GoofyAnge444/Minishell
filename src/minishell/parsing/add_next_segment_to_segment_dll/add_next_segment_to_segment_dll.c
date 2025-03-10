/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_next_segment_to_segment_dll.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:47:04 by eazard            #+#    #+#             */
/*   Updated: 2025/03/10 12:00:52 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_next_segment_to_segment_dll(t_data *data)
{
	t_segment_content	*segment_content;
	t_dll_node			*segment_node;

	segment_content = ft_calloc(1, sizeof(t_segment_content));
	if (!segment_content)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	add_cmd_name_to_segment(data, segment_content);
	add_cmd_arg_to_segment(data, segment_content);
	add_redir_tab_to_segment(data, segment_content);
	segment_node = dll_new_node((void *)segment_content);
	if (!segment_node)
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	dll_insert_tail(data -> parsing -> segment_dll, segment_node);
}


/* 

ꩇׁׅ݊ꪱׁׅ ꩇׁׅ݊ꪱׁׅ꯱ׁׅ֒hׁׅ֮ꫀׁׅܻᥣׁׅ֪ᥣׁׅ֪ ⋆｡‧˚ʚ🍓ɞ˚‧｡⋆ ~~>ceci est un test | suivi d'un' deuxieme < test
cmd_count = 2
malloc(): memory corruption (fast)
[1]    78569 IOT instruction  ./minishell

faut gerer ca ?? force a toi chef

deuxieme test ʚ🍓ɞ: ~~>ceci est un test | < test | que passo cono | bonne < question bg
*/