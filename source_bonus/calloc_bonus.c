/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/19 15:39:43 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	*ft_calloc(int count, int eltsize)
{
	int		i;
	char	*block;

	i = count * eltsize;
	if (i <= 0)
		return (0);
	block = malloc(i);
	if (block)
		while (i--)
			*(block + i) = 0;
	return ((void *)block);
}
