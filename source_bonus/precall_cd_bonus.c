/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_cd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:51:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 11:22:37 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_precall_cd(t_minishell *mini, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	return (ft_cd(mini, split[1]));
}
