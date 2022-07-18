/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:49:30 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 11:36:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	**ft_getenv_value(t_minishell *mini, char *name)
{
	t_env	*tmp;
	char	*ttmp;
	char	**tttmp;

	tmp = mini->env;
	if (!(tmp))
		return (NULL);
	if (!ft_strcmp(name, "?"))
	{
		ttmp = ft_itoa(last_error);
		tttmp = &ttmp;
		return (tttmp);
	}
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (&tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
