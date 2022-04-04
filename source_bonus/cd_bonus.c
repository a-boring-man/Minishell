/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/04 12:46:16 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(t_minishell *mini, char *s)
{
	char	*cwd;

	if ((!s || s[0] == '~') && !ft_isthere_this_env_name(mini, "HOME"))
		printf("HOME not set");
	cwd = getcwd(NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	ft_getenv(&mini, env);
	ft_cd(&mini, av[1]);
	return (0);
}
