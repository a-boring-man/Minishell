/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:50:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/11 12:24:35 by jrinna           ###   ########lyon.fr   */
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
		if (last_return && !gt[i].next_operator_type)
			while (gt[i].next_operator_type != -1 && !gt[i].next_operator_type)
				i++;
		if (!last_return && gt[i].next_operator_type)
			while (gt[i].next_operator_type != -1 && gt[i].next_operator_type)
				i++;
		if (gt[i].next_operator_type == -1)
			break ;
	}
}
