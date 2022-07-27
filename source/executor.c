/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:24 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/27 14:33:34 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_executor(t_minishell *mini, t_bt *gt)
{
	int	last_return;
	int	i;

	i = -1;
	while (1)
	{
		last_return = ft_ptit_executor(mini, gt[++i].lt);
		if (last_return)
			while (gt[i].next_operator_type == ET)
				++i;
		else
			while (gt[i].next_operator_type == OU)
				++i;
		if (gt[i].next_operator_type == -1)
			break ;
	}
	return (last_return);
}
