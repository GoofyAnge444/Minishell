/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:08:55 by ange              #+#    #+#             */
/*   Updated: 2024/11/05 18:41:36 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_index(const char *src, size_t begin, size_t end)
{
	char	*dup;
	size_t	index;

	if (end < begin)
		return (NULL);
	dup = malloc(end - begin + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (begin + index < end)
	{
		dup[index] = src[begin + index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static bool	ft_fill_tab(const char *src, char separator, char **tab)
{
	size_t	begin;
	size_t	end;
	size_t	i;

	i = 0;
	begin = 0;
	while (src[begin])
	{
		while (src[begin] && src[begin] == separator)
			begin++;
		if (src[begin] != '\0')
		{
			end = begin;
			while (src[end] && src[end] != separator)
				end++;
			tab[i] = ft_strdup_index(src, begin, end);
			if (tab[i] == NULL)
				return (ft_free_tab(tab), 0);
			i++;
			begin = end;
		}
	}
	return (1);
}

char	**ft_split(const char *src, char separator)
{
	char	**tab;

	tab = ft_calloc(ft_count_words(src, separator) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	if (ft_fill_tab(src, separator, tab))
		return (tab);
	return (NULL);
}
