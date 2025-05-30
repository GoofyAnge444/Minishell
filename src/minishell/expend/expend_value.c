/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:43 by eazard            #+#    #+#             */
/*   Updated: 2025/04/29 13:11:49 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*expend_value( t_data *data, char *value)
{
	t_dll_list	*expend_dll;
	char		*expended_value;


	if (value)
	{
		expend_dll = dll_new_list();
		if (!expend_dll)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		create_expend_list(value, data, expend_dll);
		replace_dollar_in_expend_list(expend_dll, data);
		expended_value = merge_expend_list(expend_dll);
		if (!expended_value)
			return (dll_clear_list(expend_dll, &free),
				fatal_error_clean_exit(data, MALLOC_FAILURE),
				NULL);
		dll_clear_list(expend_dll, &free);
		return (expended_value);
	}
	else
		return (NULL);
}
