/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:55:50 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/08 15:49:17 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_printf_export(t_minishell *mini)
{
	ft_ranking_env(mini->env);
}

static int	ft_export_s(t_minishell *mini, char *s)
{
	if (!ft_isthere_this_env_name(mini, ft_splitname(s)))
		ft_lstadd_back_env(&mini->env, ft_lstnew_env
			(ft_splitname(s), ft_splitvalue(s)));
	else if ()
}

int	ft_export(t_minishell *mini, char *s)
{
	if (!s)
		return (ft_print_export(mini));
	return (ft_export_s(mini, s));
}
