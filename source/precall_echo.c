/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:12 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 18:52:05 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_will(char **s, t_echo *t)
{
	if (s[t->j] && s[t->j][0] == '-')
	{
		t->i = 0;
		while (s[t->j][++(t->i)] == 'n')
			t->n = 1;
		if (s[t->j][t->i] != '\0')
			t->n = 0;
		if (t->n)
		{
			t->n = 0;
			t->supern = 1;
			(t->cs)++;
		}
	}
	(t->j)++;
}

void	ft_precall_echo(char **split)
{
	t_echo	t;

	ft_memset(&t, 0, sizeof(t_echo));
	t.j = 1;
	while (split[t.j] && split[t.j][0] == '-')
		ft_will(split, &t);
	t.i = 0;
	while (split[t.cs + ++(t.i)])
	{
		ft_echo(split[t.cs + t.i], 1);
		if (split[t.cs + t.i + 1])
			write (1, " ", 1);
	}
	if (!t.supern)
		write(1, "\n", 1);
}
