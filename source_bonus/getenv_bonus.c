/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:49:30 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/20 10:45:51 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	**ft_getenv_value(t_minishell *mini, char *name)
{
	t_env	*tmp;

	tmp = mini->env;
	if (!(tmp))
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (&tmp->value);
		tmp = tmp->next;
	}
	printf("name : %s", name);
	return (NULL);
}
