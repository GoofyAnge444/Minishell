/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_store_user_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:25 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/02/04 18:04:34 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_user_input(void)
{
	ft_putstr_fd("ꩇׁׅ݊ꪱׁׅ ꩇׁׅ݊ꪱׁׅ꯱ׁׅ֒hׁׅ֮ꫀׁׅܻᥣׁׅ֪ᥣׁׅ֪ ⋆｡‧˚ʚ🍓ɞ˚‧｡⋆ ~~>", 1);
	return (get_next_line(0));
}

static void	store_user_input_in_data(t_data *data, char *user_input)
{
	data -> user_input = user_input;
}

void	get_and_store_user_input(t_data *data)
{
	char	*user_input;

	user_input = get_user_input();
	if (!user_input)
	{
		ft_printf("exit\n");
		exit_clean(data, NOTHING);
	}
	store_user_input_in_data(data, user_input);
}

// if user_input != 0 && !*user_input,  add_history(data)
