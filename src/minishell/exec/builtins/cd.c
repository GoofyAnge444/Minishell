/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:32:03 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/07 03:59:37 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	update_pwd(t_data *data, char *old_pwd, char *new_pwd)
{
	ft_set_env_var("OLDPWD", old_pwd, data);
	ft_set_env_var("PWD", new_pwd, data);
	free(old_pwd);
	free(new_pwd);
	return (0);
}

void	ft_cd(t_segment_content *content, t_data *data)
{
	int		ret;
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	if (content -> cmd_args[2])
		ft_putstr_fd("mimishell: cd: too many arguments\n", 2);
	if (!content->cmd_args[1])
	{
		path = ft_getenv("HOME", data);
		if (!path)
			return (ft_putstr_fd("mimishell: cd: HOME not set\n", 2), 1);
	}
	else
		path = content->cmd_args[1];
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (fatal_error_clean_exit(data, 1), 1);
	ret = chdir(path);
	if (ret == -1)
		return (perror("mimishell: cd"), 1);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (fatal_error_clean_exit(data, 1), 1);
	return (update_pwd(data, old_pwd, new_pwd));
}
