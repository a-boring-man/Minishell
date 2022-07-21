/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:50 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 11:38:57 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_ranking_reset(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

static void	ft_ranking_env_correction(t_env **env, int env_size)
{
	int		cpyenv_size;
	t_env	*tmp;
	t_env	*curent;
	t_env	*cpyenv;

	curent = *env;
	cpyenv = *env;
	cpyenv_size = env_size;
	while (env_size--)
	{
		tmp = *env;
		while (tmp)
		{
			if (curent->index == tmp->index && curent != tmp)
				tmp->index++;
			tmp = tmp->next;
		}
		curent = curent->next;
	}
	*env = cpyenv;
}

static void	ft_ranking_env(t_env **env, int env_size)
{
	int		cpyenv_size;
	t_env	*tmp;
	t_env	*curent;
	t_env	*cpyenv;

	curent = *env;
	cpyenv = *env;
	cpyenv_size = env_size;
	ft_ranking_reset(env);
	while (env_size--)
	{
		tmp = *env;
		while (tmp)
		{
			if (ft_strcmp(curent->name, tmp->name) > 0 && curent != tmp)
				curent->index++;
			tmp = tmp->next;
		}
		curent = curent->next;
	}
	*env = cpyenv;
	ft_ranking_env_correction(env, cpyenv_size);
}

static void	ft_printf_export(t_minishell *mini)
{
	int		i;
	int		env_size;
	t_env	*tmp;

	i = 0;
	env_size = 0;
	tmp = mini->env;
	while (tmp)
	{
		env_size++;
		tmp = tmp->next;
	}
	ft_ranking_env(&mini->env, env_size);
	while (++i < env_size + 1)
	{
		tmp = mini->env;
		while (tmp)
		{
			if (tmp->index == i - 1 && tmp->value && ft_strcmp(tmp->name, "_"))
				ft_dprintf(1, "declare -x %s=\"%s\"\n", tmp->name, tmp->value);
			else if (tmp->index == i - 1 && ft_strcmp(tmp->name, "_"))
				ft_dprintf(1, "declare -x %s\n", tmp->name);
			tmp = tmp->next;
		}
	}
}

int	ft_export(t_minishell *mini, char *s)
{
	int		last_return;
	char	*name;

	last_return = 0;
	if (!s)
		ft_printf_export(mini);
	name = ft_splitname(s);
	if (s && ft_is_it_a_valid_env_name(name) && *s)
	{
		if (!ft_isthere_this_env_name(mini, name))
			ft_lstadd_back_env(&mini->env, ft_lstnew_env
				(ft_splitname(s), ft_splitvalue(s)));
		else
			*ft_getenv_value(mini, name) = ft_splitvalue(s);
	}
	else
	{
		ft_dprintf(2,
			"minishell_bonus: export: `%s': not a valid identifier\n", s);
		last_return = 1;
	}
	ft_free((void **)&name);
	return (last_return);
}
