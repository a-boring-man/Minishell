/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_export_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/19 13:06:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_precall_export(t_minishell *mini, char *line)
{
	char	**split;
	int		i;
	int		last_return;

	i = 1;
	last_return = 0;
	split = ft_split(line, ' ');
	if (ft_export(mini, split[1]))
		last_return = 1;
	while (split[i] && split[i + 1])
		if (ft_export(mini, split[++i]))
			last_return = 1;
	return (last_return);
}
