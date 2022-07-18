/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_unset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:08 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 11:54:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_unset(t_minishell *mini, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		if (ft_unset(mini, split[i]))
			last_error = 1;
}
