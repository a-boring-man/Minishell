/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/06 12:26:58 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	char	*cwd;

	if ((!s || s[0] == '~' || (s[0] == '-' && s[1] == '-' && !s[2]))
		&& !ft_isthere_this_env_name(mini, "HOME"))
		printf("HOME not set");
	if ((!s || (s[0] == '-' && s[1] == '-' && !s[2]))
		&& ft_isthere_this_env_name(mini, "HOME"))
		ft_cd(mini, ft_getenv_value(mini, "HOME"));
	if (s[0] == '~' && ft_isthere_this_env_name(mini, "HOME"))
		ft_cd(mini, ft_strjoin());
	cwd = getcwd(NULL, 0);
	if (!s && ft_isthere_this_env_name(mini, "HOME"))
	{
		chdir(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	ft_getenv(&mini, env);
	ft_cd(&mini, av[1]);
	return (0);
}
