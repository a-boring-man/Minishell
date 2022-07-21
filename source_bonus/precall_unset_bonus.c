/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_unset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:08 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 11:16:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_precall_unset(t_minishell *mini, char **split)
{
	int		i;
	int		last_return;

	i = 0;
	last_return = 0;
	if (!split)
		return (1);
	while (split[++i])
		if (ft_unset(mini, split[i]))
			last_return = 1;
	return (last_return);
}
