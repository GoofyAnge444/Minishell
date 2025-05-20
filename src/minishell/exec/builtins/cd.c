/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:32:03 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/20 15:59:37 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	update_pwd(t_data *data, char *old_pwd, char *new_pwd)
{
	set_var_in_list(data->env, "OLDPWD", old_pwd, data);
	set_var_in_list(data->env, "PWD", new_pwd, data);
	free(old_pwd);
	free(new_pwd);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

void	ft_cd(t_segment_content *content, t_data *data)
{
	int		ret;
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	if (ft_tablen(content -> cmd_args) > 2)
		ft_putstr_fd("mimishell: cd: too many arguments\n", 2);
	if (!content->cmd_args[1])
	{
		path = ft_getenv("HOME", data);
		if (!path)
			return (ft_putstr_fd("mimishell: cd: HOME not set\n", 2));
	}
	else
		path = content->cmd_args[1];
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (fatal_error_clean_exit(data, MALLOC_FAILURE));
	ret = chdir(path);
	if (ret == -1)
		return (perror("mimishell: cd"));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (free(old_pwd), fatal_error_clean_exit(data, MALLOC_FAILURE));
	update_pwd(data, old_pwd, new_pwd);
}
