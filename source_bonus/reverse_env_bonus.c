/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_env_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:43:06 by jrinna            #+#    #+#             */
/*   Updated: 2022/06/17 11:56:33 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_reverse_env(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			i++;
		tmp = tmp->next;
	}
}
