/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:38 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/26 14:08:33 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_s(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	ft_ranking_reset(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

void	ft_dollar_end_if(t_minishell *m, char **ttmp, char *tmp)
{
	char	**tttmp;

	*ttmp = NULL;
	tttmp = ft_getenv_value(m, tmp);
	if (tttmp)
		*ttmp = *tttmp;
}
