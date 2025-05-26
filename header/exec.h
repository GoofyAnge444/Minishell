/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:35:36 by cboma-ya          #+#    #+#             */
/*   Updated: 2025/05/26 19:42:13 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "minishell.h"
# include <sys/wait.h>

typedef struct s_segment_content	t_segment_content;
typedef struct s_env_content		t_env_content;


void	exec(t_data *data, t_dll_list *lst);
void	set_var_in_list(t_dll_list *list, char *name,
			char *value, t_data *data);
// void	ft_set_env(t_env_content *tmp_env, t_data *data);
// void	ft_set_env_var(const char *name, const char *value, t_data *data);
char	*ft_getenv(char *name, t_data *data);
void	freeing_experience(t_env_content *tmp_env, t_data *data);
void	ft_echo(t_segment_content *content);
void	ft_exit(t_segment_content *content, t_data *data);
void	ft_pwd(void);
void	ft_env(t_data *data);
void	ft_cd(t_segment_content *content, t_data *data);
void	ft_export(t_segment_content *content, t_data *data);
void	ft_unset(t_segment_content *content, t_data *data);

#endif