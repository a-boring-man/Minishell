/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:47:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/31 15:00:54 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	*ft_calloc(int count, int eltsize)
{
	int		i;
	char	*block;

	i = -1;
	block = malloc(count * eltsize);
	if (block)
		while (i < count * eltsize - 1)
			*(block + ++i) = 0;
	return ((void *)block);
}
