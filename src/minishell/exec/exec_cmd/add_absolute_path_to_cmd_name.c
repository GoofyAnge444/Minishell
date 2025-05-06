/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_absolute_path_to_cmd_name.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:51:14 by eazard            #+#    #+#             */
/*   Updated: 2025/05/06 14:30:58 by eazard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**get_bin_paths(t_data *data, char **envp)
{
	size_t	i;
	char	**bin_paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			bin_paths = ft_split(envp[i] + 5, ':');
			if (!bin_paths)
				fatal_error_clean_exit(data, MALLOC_FAILURE);
			return (bin_paths);
		}
		i++;
	}
	bin_paths = malloc(sizeof(char *));
	*bin_paths = NULL;
	return (bin_paths);
}

void	add_absolute_path_to_cmd_name(t_data *data, t_cmd_content *content)
{
	char	*potential_asolute_cmd_path;
	size_t	i;

	if (!data -> exec -> bin_paths)
		data -> exec -> bin_paths = get_bin_paths(data, data -> exec -> envp);
	i = 0;
	while (data -> exec -> bin_paths[i])
	{
		potential_asolute_cmd_path
			= ft_strjoin_with_separator(data -> exec -> bin_paths[i],
				content -> cmd_name, '/');
		if (!potential_asolute_cmd_path)
			fatal_error_clean_exit(data, MALLOC_FAILURE);
		if (0 == access(potential_asolute_cmd_path, F_OK))
		{
			free(content -> cmd_name);
			content -> cmd_name = potential_asolute_cmd_path;
			return ;
		}
		free(potential_asolute_cmd_path);
		potential_asolute_cmd_path = NULL;
		i++;
	}
	ft_printf_fd(2, "minishell: %s: command not found\n", content -> cmd_name);
	fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
}
