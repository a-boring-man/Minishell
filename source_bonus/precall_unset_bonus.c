/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_unset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:08 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/19 13:03:25 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_precall_unset(t_minishell *mini, char *line)
{
	int		i;
	char	**split;
	int		last_return;

	i = 0;
	last_return = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		if (ft_unset(mini, split[i]))
			last_return = 1;
	return (last_return);
}
