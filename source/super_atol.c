/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:47 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_third_while(char *s, int *i, int *sgn)
{
	if (s[*i] == 45)
		*sgn = -*sgn;
	(*i)++;
}

static void	ft_fourth_while(long *p, long *n, int *i, char *s)
{
	*p = *n;
	*n = *n * 10 + (s[*i] - '0');
	(*i)++;
}

static void	ft_skip(char *s, int *i)
{
	*i = 0;
	while ((s[*i] > 8 && s[*i] < 14) || s[*i] == 32)
		(*i)++;
}

int	ft_super_atol(char *s)
{
	long	next;
	long	previous;
	int		sgn;
	int		i;

	i = -1;
	sgn = 1;
	next = 0;
	previous = 0;
	if (!s)
		return (0);
	while (s[++i])
		if (!((s[i] > 8 && s[i] < 14) || s[i] == 32 || s[i] == 43 || s[i] == 45
				|| (s[i] > 47 && s[i] < 58)))
			return (-1);
	ft_skip(s, &i);
	while (s[i] == 43 || s[i] == 45)
		ft_third_while(s, &i, &sgn);
	while (s[i] > 47 && s[i] < 58)
	{
		ft_fourth_while(&previous, &next, &i, s);
		if ((sgn == 1 && next < previous) || (sgn == -1 && next > previous))
			return (-1);
	}
	return ((sgn * next) & 255);
}
