/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:32:03 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/03/26 00:25:05 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_segment_content *content, t_data *data)
{
	if (content -> cmd_args[2])
		ft_putstr_fd("cd: too many arguments\n",2);
	chdir()
}
