/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:18:10 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/01 15:44:42 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_splitname(char *env)
{}

char	*ft_splitvalue(char *env)
{}

int	ft_getenv(t_minishell *mini, char **env)
{
	int	i;

	i = 0;
	mini->env = NULL;
	if (!env)
		return (1);
	while (env[i])
	{
		mini->env = ft_lstnew_env(ft_splitname(env[i]), ft_splitvalue(env[i]));
	}
}
