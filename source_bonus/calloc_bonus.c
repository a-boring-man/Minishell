/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/11 11:28:37 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_memset(void *block, int c, unsigned long size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		*(unsigned char *)(block + i) = (unsigned char)c;
		i++;
	}
}

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
