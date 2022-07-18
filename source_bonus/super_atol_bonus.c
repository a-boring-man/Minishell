/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_atol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:12:51 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 11:29:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_super_atol(char *s)
{
	long	next;
	long	previous;
	int		sgn;
	int		i;

	i = 0;
	sgn = 1;
	next = 0;
	previous = 0;
	if (!s)
		return (0);
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	while (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			sgn = -sgn;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		previous = next;
		next = next * 10 + (s[i] - '0');
		i++;
		if ((sgn == 1 && next < previous) || (sgn == -1 && next > previous))
			return (-1);
	}
	return (sgn * next & 11111111);
}
