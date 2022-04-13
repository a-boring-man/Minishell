/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist_env2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:07:43 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/13 12:48:43 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_delnode_env_ns(t_minishell *mini, char *name)
{
	t_env	*tmp_previous;
	t_env	*tmp;

	tmp = mini->env->next;
	tmp_previous = mini->env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_max(tmp->name_lengh,
					ft_strlen_s(name))))
		{
			tmp_previous->next = tmp->next;
			ft_lstdelone_env(tmp);
			break ;
		}
		tmp = tmp->next;
		tmp_previous = tmp_previous->next;
	}
}

void	ft_delnode_env_ns_f(t_minishell *mini, char *name)
{
	t_env	*tmp_next;
	t_env	*tmp;

	tmp = mini->env;
	tmp_next = tmp->next;
	if (!tmp)
		return ;
	if (!ft_strncmp(tmp->name, name, ft_max(tmp->name_lengh,
				ft_strlen_s(name))))
	{
		ft_lstdelone_env(tmp);
		mini->env = tmp_next;
	}
	else
		ft_delnode_env_ns(mini, name);
}

void	ft_lstdelone_env(t_env *env)
{
	ft_free((void **)&(env->name));
	ft_free((void **)&(env->value));
	ft_free((void **)&env);
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
