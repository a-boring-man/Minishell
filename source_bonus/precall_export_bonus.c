/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_export_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:52:42 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/02 12:44:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_export(t_minishell *mini, char *line)
{
	char	**split;
	int		i;

	i = 1;
	split = ft_split(line, ' ');
	ft_export(mini, split[1]);
	while (split[i] && split[i + 1])
		ft_export(mini, split[++i]);
}
