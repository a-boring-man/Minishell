/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:18:33 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/30 13:06:10 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_only

void	ft_echo(char *s)
{
	int	i;

	i = -1;
	if (!s || !*s)
		return ;
	while (s[++i])
	{
		if (s[i] == '\\')
			i++;
		else
			write(STDOUT_FILENO, &s[i], 1);
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_echo(av[1]);
}
