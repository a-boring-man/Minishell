/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:18:33 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/31 10:27:00 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_echo(char *s, int fd, int n)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	i++;
	write(fd, s, i);
	if (!n)
		write(fd, "\n", 1);
}
