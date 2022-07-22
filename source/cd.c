/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:08 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:35:41 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_cd(t_minishell *mini, char *s, char *current_dir, int *ret)
{
	if (!s && !ft_isthere_this_env_name(mini, "HOME"))
	{
		ft_dprintf(2, "HOME not set\n");
		*ret = 1;
	}
	else if (!s && !chdir (*ft_getenv_value(mini, "HOME")))
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
	oldppwd = ft_getenv_value(mini, "OLDPWD");
	if (oldppwd)
		oldpwd = *ft_getenv_value(mini, "OLDPWD");
	current_directory = getcwd(NULL, 0);
	check_cd(mini, s, current_directory, &last_return);
	pwd = getcwd(NULL, 0);
	ft_export(mini, ft_strjoin_nf("OLDPWD=", oldpwd), 1);
	ft_export(mini, ft_strjoin_nf("PWD=", pwd), 1);
	ft_free((void **)&pwd);
	ft_free((void **)&current_directory);
	return (last_return);
}
