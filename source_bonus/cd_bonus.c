/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/07 13:45:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	char	*cwd;

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
		s = ft_strjoin_nf(ft_getenv_value(mini, "HOME"), s + 1);
	cwd = getcwd(NULL, 0);
	printf("cwd : %s\n", cwd);
	cwd = ft_strjoin_f(cwd, "/");
	printf("cwd : %s\n", cwd);
	cwd = ft_strjoin_f(cwd, s);
	printf("cwd : %s\n", cwd);
	chdir(cwd);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	ft_env_init(&mini, env);
	ft_cd(&mini, av[1]);
	printf("cd finish\n");
	return (0);
}
