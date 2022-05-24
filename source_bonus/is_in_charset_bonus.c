/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_charset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:38:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/09 12:51:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_isincharset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}
