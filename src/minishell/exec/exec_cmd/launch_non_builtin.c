/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_non_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:13:38 by eazard            #+#    #+#             */
/*   Updated: 2025/05/21 18:15:32 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	launch_non_builtin(t_cmd_content *content, t_data *data)
{
	check_and_search_for_abs_path(data, content);
	return (execve(content -> cmd_name, content -> cmd_args,
			data -> exec -> envp));
}
