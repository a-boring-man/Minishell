/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:06 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
