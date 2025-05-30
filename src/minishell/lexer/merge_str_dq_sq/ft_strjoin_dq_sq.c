/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_dq_sq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:40:54 by eazard            #+#    #+#             */
/*   Updated: 2025/02/17 16:34:51 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static size_t	get_len_dq_sq(char *str, t_token_type type)
{
	size_t	len;

	len = ft_strlen(str);
	if (type == DQ_TK || type == SQ_TK)
		len -= 2;
	return (len);
}

static void	join_prefix(char *joined_string, char *prefix
	, size_t prefix_len, t_token_type prefix_type)
{
	size_t	index;
	size_t	offset;

	if (prefix_type == DQ_TK || prefix_type == SQ_TK)
		offset = 1;
	else
		offset = 0;
	index = 0;
	while (index < prefix_len)
	{
		joined_string[index] = prefix[offset + index];
		index++;
	}
}

static void	join_suffix(char *joined_string, char *suffix
		, size_t suffix_len, t_token_type suffix_type)
{
	size_t	index;
	size_t	offset;
	size_t	prefix_len;

	prefix_len = 0;
	while (joined_string[prefix_len])
		prefix_len++;
	if (suffix_type == DQ_TK || suffix_type == SQ_TK)
		offset = 1;
	else
		offset = 0;
	index = 0;
	while (index < suffix_len)
	{
		joined_string[prefix_len + index] = suffix[offset + index];
		index++;
	}
}

char	*ft_strjoin_dq_sq(char *prefix, char *suffix, t_token_type prefix_type
		, t_token_type suffix_type)
{
	char	*joined_string;
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = get_len_dq_sq(prefix, prefix_type);
	suffix_len = get_len_dq_sq(suffix, suffix_type);
	joined_string = ft_calloc(prefix_len + suffix_len + 1, 1);
	if (joined_string == 0)
		return (NULL);
	join_prefix(joined_string, prefix, prefix_len, prefix_type);
	join_suffix(joined_string, suffix, suffix_len, suffix_type);
	return (joined_string);
}
