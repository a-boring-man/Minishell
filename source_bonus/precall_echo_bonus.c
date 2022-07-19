/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_echo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:51:24 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/19 12:54:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_precall_echo(char *line)
{
	char	**split;
	int		n;
	int		i;

	i = 0;
	n = 0;
	split = ft_split(line, ' ');
	if (split[1] && !ft_strcmp(split[1], "-n"))
		n++;
	while (split[++i + n])
	{
		ft_echo(split[i + n], 1);
		if (split[i + n + 1])
			write (1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
	return (0);
}
