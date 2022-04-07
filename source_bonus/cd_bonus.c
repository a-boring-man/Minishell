/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/07 15:50:16 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	if ((!s || s[0] == '~' || (s[0] == '-' && s[1] == '-' && !s[2]))
		&& !ft_isthere_this_env_name(mini, "HOME"))
	{
		printf("HOME not set");
		return ;
	}
	if ((!s || (s[0] == '-' && s[1] == '-' && !s[2]) || (s[0] == '~' && !s[1]))
		&& ft_isthere_this_env_name(mini, "HOME"))
	{
		chdir(ft_getenv_value(mini, "HOME"));
		return ;
	}
	if (s[0] == '~' && ft_isthere_this_env_name(mini, "HOME"))
	{
		chdir(ft_getenv_value(mini, "HOME"));
		
	}
	else
	{
		cwd = getcwd(NULL, 0);
		cwd = ft_strjoin_f(cwd, "/");
	}
	printf("cwd avant: %s\n", cwd);
	cwd = ft_strjoin_f(cwd, s);
	printf("cwd apres: %s\n", cwd);
	chdir(cwd);
	ft_free((void **)&cwd);
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
