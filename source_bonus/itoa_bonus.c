/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:22:12 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 09:22:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_count(int nbr)
{
	int	count;

	count = 2;
	if (nbr < 0)
		count++;
	while (nbr / 10)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*string;
	int		count;
	int		start;

	nbr = n;
	start = 0;
	count = ft_count(nbr);
	string = malloc(count);
	if (string != 0)
	{
		string[count - 1] = 0;
		if (nbr < 0)
		{
			string[0] = '-';
			nbr = -nbr;
			start++;
		}
		while (count-- > start + 1)
		{
			string[count - 1] = (nbr % 10) + '0';
			nbr = nbr / 10;
		}
	}
	return (string);
}
