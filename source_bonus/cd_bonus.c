/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/19 17:29:04 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	char	*oldpwd;
	char	*current_directory;
	char	*pwd;

	oldpwd = *ft_getenv_value(mini, "OLDPWD");
	current_directory = getcwd(NULL, 0);
	if (!s && !ft_isthere_this_env_name(mini, "HOME"))
		printf("HOME not set\n");
	else if (!s && !chdir (*ft_getenv_value(mini, "HOME")))
		oldpwd = current_directory;
	else if (s && !chdir(s))
		oldpwd = current_directory;
	else
		printf("No such file or directory\n");
	pwd = getcwd(NULL, 0);
	ft_export(mini, ft_strjoin_nf("OLDPWD=", oldpwd));
	ft_export(mini, ft_strjoin_nf("PWD=", pwd));
}

/* int	main(int ac, char **av, char **env)
{
	t_minishell	mini;
	char		*tmp;

	(void)ac;
	ft_env_init(&mini, env);
	printf("\n\n  --  env before  --  \n\n");
	ft_export(&mini, NULL);
	ft_cd(&mini, av[1]);
	printf("\n\n  --  env after  --  \n\n");
	ft_export(&mini, NULL);
	tmp = getcwd(NULL, 0);
	printf("\n\ncwd = %s\n\n\n", tmp);
	ft_free((void **)&tmp);
	printf("cd finish\n");
	ft_lstclear_env(&(mini.env));
	return (0);
} */
