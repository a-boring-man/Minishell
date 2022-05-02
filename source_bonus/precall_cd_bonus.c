/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_cd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:51:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/02 11:54:33 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_cd(t_minishell *mini, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_cd(mini, split[1]))
		printf("cd succed\n");
	else
		printf("cd fail\n");
}
