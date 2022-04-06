/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:49:05 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/06 11:49:08 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_isthere_this_env_name(t_minishell *mini, char *s)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, s))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
