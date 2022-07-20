/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:28:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 12:33:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s && fd > -1)
	{
		while (s[++i])
			write(fd, &s[i], 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > -1)
		write(fd, &c, 1);
}

void	ft_clean(char **tab)
{
	int	j;

	j = -1;
	while (tab[++j])
		free(tab[j]);
	free(tab);
	return ;
}
