/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_echo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:51:24 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:09:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_echo(char **split)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (split[1] && split[1][0] == '-')
	{
		while (split[1][++i] == 'n')
			n = 1;
	 	if (split[1][i] != '\0')
			n = 0;
	}
	i = 0;
	while (split[++i + n])
	{
		ft_echo(split[i + n], 1);
		if (split[i + n + 1])
			write (1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
}
