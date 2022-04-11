/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:50 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/11 12:51:19 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_printf_export(t_minishell *mini)
{
	int		i;
	int		env_size;
	t_env	*tmp;

	i = 1;
	env_size = 0;
	tmp = mini->env;
	while (tmp)
	{
		env_size++;
		tmp = tmp->next;
	}
	ft_ranking_env(mini->env);
	while (i < env_size + 1)
	{
		tmp = mini->env;
		while (tmp)
		{
			if (tmp->index == i && tmp->value)
				printf("declare -x %s=\"%s\"", tmp->name, tmp->value);
			else if (tmp->index == i)
				printf("declare -x %s", tmp->name);
			tmp = tmp->next;
		}
		i++;
	}
}

static int	ft_export_s(t_minishell *mini, char *s)
{
	if (!s)
		ft_printf_export(mini);
	else if (!ft_isthere_this_env_name(mini, ft_splitname(s)))
		ft_lstadd_back_env(&mini->env, ft_lstnew_env
			(ft_splitname(s), ft_splitvalue(s)));
	else if (ft_getenv_value(mini, s) && *ft_getenv_value(mini, s))
		*ft_getenv_value(mini, s) = ft_splitvalue(s);
}

int	ft_export(t_minishell *mini, char *s)
{
	if (!s)
		return (ft_print_export(mini));
	return (ft_export_s(mini, s));
}
