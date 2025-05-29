/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazard <eazard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:32:03 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/29 17:58:03 by eazard           ###   ########.fr       */
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

void	ft_cd(t_cmd_content *content, t_data *data)
{
	int		ret;
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	if (ft_tablen(content -> cmd_args) > 2)
		return (set_last_exit_code(data, 1), (void)ft_putstr_fd("mishell: cd: too many arguments\n", 2));
	if (!content->cmd_args[1])
	{
		path = ft_getenv("HOME", data);
		if (!path)
			return (set_last_exit_code(data, 1), ft_putstr_fd("mishell: cd: HOME not set\n", 2));
	}
	else
		path = content->cmd_args[1];
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (set_last_exit_code(data, 1), fatal_error_clean_exit(data, MALLOC_FAILURE));
	ret = chdir(path);
	if (ret == -1)
		return (set_last_exit_code(data, 1), free(old_pwd), perror("mishell: cd"));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (free(old_pwd), set_last_exit_code(data, 1), fatal_error_clean_exit(data, MALLOC_FAILURE));
	update_pwd(data, old_pwd, new_pwd);
	set_last_exit_code(data, 0); 
}
