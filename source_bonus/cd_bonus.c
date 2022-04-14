/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/14 14:12:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	char	*oldpwd;
	char	*pwd;

	oldpwd = *ft_getenv_value(mini, "OLDPWD");
	if (s && !chdir(s))
		oldpwd = getcwd(NULL, 0);
	else if (!s && !ft_isthere_this_env_name(mini, "HOME"))
		printf("HOME not set\n");
	else if (!s)
		if (!chdir (*ft_getenv_value(mini, "HOME")))
			oldpwd = getcwd(NULL, 0);
	pwd = getcwd(NULL, 0); // message d'error a faire
	printf("oldpwd : %s\n", oldpwd);
	printf("pwd : %s\n", pwd);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;
	char		*tmp;

	(void)ac;
	ft_env_init(&mini, env);
	ft_cd(&mini, av[1]);
	tmp = getcwd(NULL, 0);
	printf("\n\ncwd = %s\n\n\n", tmp);
	ft_free((void **)&tmp);
	printf("cd finish\n");
	ft_lstclear_env(&(mini.env));
	return (0);
}
