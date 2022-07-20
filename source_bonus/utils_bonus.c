/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:28:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 14:35:20 by jrinna           ###   ########lyon.fr   */
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
	if (!tab)
		return ;
	while (tab[++j])
	{
		if (tab[j])
			ft_dprintf(1, "-haaa-%s\n", tab[j]);
		free(tab[j]);
	}
	free(tab);
	return ;
}
