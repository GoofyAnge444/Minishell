/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_token_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:43 by eazard            #+#    #+#             */
/*   Updated: 2025/02/12 19:04:38 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

// static void	ft_pustr(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	write(1, "->", 2);
// 	while (str[i])
// 	{
// 		write (1, &str[i], 1);
// 		i++;
// 	}
// 	write(1, "<-", 2);
// 	write(1, "\n", 1);
// }

void	expend_token_value(t_token_content *token_content, t_data *data)
{
	t_dll_list	*expend_dll;
	char		*expended_value;


	expend_dll = dll_new_list();
	if (!expend_dll)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	create_expend_list(token_content, data, expend_dll);
	replace_dollar_in_expend_list(expend_dll, data);
	expended_value = merge_expend_list(expend_dll);
	if (!expended_value)
		return (dll_clear_list(expend_dll, &free),
			fatal_error_clean_exit(data, MALLOC_FAILURE));
	free(token_content -> value);
	dll_clear_list(expend_dll, &free);
	token_content -> value = expended_value;
}
