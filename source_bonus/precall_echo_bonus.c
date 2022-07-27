/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_echo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:51:24 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/27 14:27:32 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_will(char *s, int *supern)
{
	int	i;
	int	n;

	n = 0;
	if (!(s && s[0] == '-'))
		return (0);
	i = 0;
	while (s[++i] == 'n')
		n = 1;
	if (s[i] != '\0' || !n)
		return (0);
	*supern = 1;
	return (1);
}

void	ft_precall_echo(char **split)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	while (ft_will(split[i], &n))
		++(i);
	j = -1;
	while (split[i + ++j])
	{
		ft_echo(split[i + j], 1);
		if (split[i + j + 1])
			write (1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
}
