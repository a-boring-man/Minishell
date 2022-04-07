/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:49:30 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/07 11:51:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_getenv_value(t_minishell *mini, char *name)
{
	t_env	*tmp;

	tmp = mini->env;
	if (!(tmp))
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name) && tmp->name_lengh == ft_strlen_s(name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
