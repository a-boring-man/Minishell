/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_export_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 11:51:55 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_export(t_minishell *mini, char *line)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_split(line, ' ');
	if (ft_export(mini, split[1]))
		last_error = 1;
	while (split[i] && split[i + 1])
		if (ft_export(mini, split[++i]))
			last_error = 1;
}
