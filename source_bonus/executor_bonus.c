/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:50:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/22 12:11:18 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_executor(t_minishell *mini, t_grostoken *gt)
{
	int	last_return;
	int	i;

	i = -1;
	while (1)
	{
		last_return = ft_ptit_executor(mini, gt[++i].petit_token);
		if (last_return)
			while (gt[i].next_operator_type == ET)
				++i;
		else
			while (gt[i].next_operator_type == OU)
				++i;
		if (gt[i].next_operator_type == -1)
			break ;
	}
}
