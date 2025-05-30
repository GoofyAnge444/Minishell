/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_tab_to_segment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:52:10 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 16:45:22 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	there_is_redir_tk_in_this_segment(t_dll_node *first_token_of_cmd)
{
	t_dll_node	*token;

	token = first_token_of_cmd;
	while (token && !is_a_pipe_token(token))
	{
		if (is_a_redir_token(token))
			return (true);
		token = token -> next;
	}
	return (false);
}

static void	fill_redir_tab_content(t_data *data,
	t_segment_content *segment_content,
	t_dll_node *token, int i)
{
	((segment_content->redir_tab)[i])-> filename
		= ft_strdup(get_token_value(token -> next));
	if (!((segment_content->redir_tab)[i])-> filename)
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	((segment_content->redir_tab)[i])-> redir_type
		= (int)(((t_token_content *)(token ->content))->type);
	if (((t_token_content *)(token ->content))->heredoc__no_expend == true)
		segment_content ->redir_tab[i]-> heredoc__expend_env_var = false;
	else
		segment_content ->redir_tab[i]-> heredoc__expend_env_var = true;
}

static void	add_all_redir_in_redir_tab(t_data *data,
	t_segment_content *segment_content, t_dll_node *first_token_of_segment)
{
	t_dll_node	*token;
	int			i;

	token = first_token_of_segment;
	i = 0;
	while (token && !is_a_pipe_token(token))
	{
		if (is_a_redir_token(token))
		{
			(segment_content->redir_tab)[i] = ft_calloc(1, sizeof(t_redir));
			if (!(segment_content->redir_tab)[i])
				return (free_segment_content(segment_content),
					fatal_error_clean_exit(data, MALLOC_FAILURE));
			fill_redir_tab_content(data, segment_content, token, i);
			i++;
		}
		token = token -> next;
	}
	(segment_content -> redir_tab)[i] = NULL;
}

static void	allocate_redir_tab_space(t_data *data,
		t_segment_content *segment_content, t_dll_node *first_token_of_segment)
{
	segment_content -> redir_tab
		= ft_calloc(count_redir_nb_in_this_segment(first_token_of_segment) + 1, \
		sizeof(t_redir *));
	if (!segment_content -> redir_tab)
		return (free_segment_content(segment_content),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
}

void	add_redir_tab_to_segment(t_data *data,
			t_segment_content *segment_content)
{
	t_dll_node	*first_token_of_segment;

	first_token_of_segment = get_first_token_of_segment(data);
	if (there_is_redir_tk_in_this_segment(first_token_of_segment))
	{
		allocate_redir_tab_space(data, segment_content, first_token_of_segment);
		add_all_redir_in_redir_tab(data, segment_content,
			first_token_of_segment);
	}
	else
		segment_content -> redir_tab = NULL;
}
