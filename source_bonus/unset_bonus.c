/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:30:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:37:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_unset(t_minishell *mini, char *s)
{
	if (!s)
		return (1);
	if (!ft_is_it_a_valid_env_name(s))
	{
		ft_dprintf(2, "%s: unset: `%s': not a valid identifier", mini->name, s);
		return (1);
	}
	if (ft_isthere_this_env_name(mini, s))
		ft_delnode_env_ns_f(mini, s);
	return (0);
}
