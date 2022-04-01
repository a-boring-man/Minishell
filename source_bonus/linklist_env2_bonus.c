/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_env2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:07:43 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/01 14:16:01 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_lstdelone_env(t_env *env)
{
	ft_free(&(env->name));
	ft_free(&(env->value));
	ft_free(&env);
}

int	ft_lstsize_env(t_env *env)
{
	int		counter;
	t_env	*tmp;

	counter = 1;
	tmp = env;
	if (!env)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}
