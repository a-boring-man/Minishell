/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:18:33 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 13:14:31 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_echo(char *s, int fd)
{
	int	i;

	i = 0;
	ft_dprintf(1, "coucou\n");
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}
