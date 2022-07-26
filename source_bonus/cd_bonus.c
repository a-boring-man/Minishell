/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/26 13:34:53 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	check_cd(t_minishell *mini, char *s, char *current_dir, int *ret)
{
	if (!s && !ft_isthere_this_env_name(mini, "HOME"))
	{
		ft_dprintf(2, "HOME not set\n");
		*ret = 1;
	}
	else if (!s && ft_getenv_value(mini, "HOME") && !chdir
		(*ft_getenv_value(mini, "HOME")))
		ft_export(mini, ft_strjoin_nf("OLDPWD=", current_dir), 1);
	else if (s && !chdir(s))
		ft_export(mini, ft_strjoin_nf("OLDPWD=", current_dir), 1);
	else
	{
		ft_dprintf(2, "No such file or directory\n");
		*ret = 1;
	}
}

int	ft_cd(t_minishell *mini, char *s)
{
	char	*oldpwd;
	char	**oldppwd;
	char	*current_directory;
	char	*pwd;
	int		last_return;

	last_return = 0;
	oldpwd = NULL;
	current_directory = getcwd(NULL, 0);
	check_cd(mini, s, current_directory, &last_return);
	pwd = getcwd(NULL, 0);
	oldppwd = ft_getenv_value(mini, "OLDPWD");
	if (oldppwd)
		oldpwd = *ft_getenv_value(mini, "OLDPWD");
	ft_export(mini, ft_strjoin_nf("OLDPWD=", oldpwd), 1);
	ft_export(mini, ft_strjoin_nf("PWD=", pwd), 1);
	ft_free((void **)&pwd);
	ft_free((void **)&current_directory);
	return (last_return);
}
