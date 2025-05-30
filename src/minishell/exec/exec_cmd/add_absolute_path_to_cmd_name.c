/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_absolute_path_to_cmd_name.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:51:14 by eazard            #+#    #+#             */
/*   Updated: 2025/05/30 17:27:36 by eazard           ###   ########.fr       */
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

static int	test_if_is_cmd_in_this_bin_dir(t_data *data, t_cmd_content *content,
				size_t i)
{
	char	*potential_asolute_cmd_path;

	potential_asolute_cmd_path
		= ft_strjoin_with_separator(data -> exec -> bin_paths[i],
			content -> cmd_name, '/');
	if (!potential_asolute_cmd_path)
		fatal_error_clean_exit(data, MALLOC_FAILURE);
	if (0 == access(potential_asolute_cmd_path, F_OK))
	{
		free(content -> cmd_name);
		content -> cmd_name = potential_asolute_cmd_path;
		return (1);
	}
	free(potential_asolute_cmd_path);
	potential_asolute_cmd_path = NULL;
	return (0);
}

void	add_absolute_path_to_cmd_name(t_data *data, t_cmd_content *content)
{
	size_t	i;

	if ('\0' == content->cmd_name[0])
	{
		ft_printf_fd(2, "mishell: : command not found\n");
		fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
	}
	if (!data -> exec -> bin_paths)
		data -> exec -> bin_paths = get_bin_paths(data, data -> exec -> envp);
	i = 0;
	while (data -> exec -> bin_paths[i])
	{
		if (1 == test_if_is_cmd_in_this_bin_dir(data, content, i))
			return ;
		i++;
	}
	ft_printf_fd(2, "mishell: %s: command not found\n", content -> cmd_name);
	fatal_error_clean_exit(data, COMMAND_NOT_FOUND);
}
