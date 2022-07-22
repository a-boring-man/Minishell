/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:21 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:35:50 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
