/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_exit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:56 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 11:20:17 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_numeric_argument(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!((s[i] > 8 && s[i] < 14) || s[i] == 32 || s[i] == 43 || s[i] == 45
				|| (s[i] > 47 && s[i] < 58)))
			return (1);
	}
	return (0);
}

void	ft_precall_exit(char **split, int last_return)
{
	if (!split)
		return ;
	if (split[1] && split[2])
	{
		if (ft_numeric_argument(split[1]))
			ft_dprintf(2,
				"minishell_bonus: exit: %s: numeric argument required\n",
				split[1]);
		else
			ft_dprintf(2, "minishell_bonus: exit: too many arguments\n");
		return ;
	}
	last_return = ft_exit(split[1]);
	if (last_return == -1)
		ft_dprintf(2,
			"minishell_bonus: exit: %s: numeric argument required\n", split[1]);
	if (last_return == -1)
		last_return = 255;
	exit (last_return);
}
