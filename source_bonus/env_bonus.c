/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:39:31 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:37:09 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_env(t_minishell *mini)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (*ft_getenv_value(mini, tmp->name))
			ft_dprintf(1, "%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}
