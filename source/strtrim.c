/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:40 by jrinna            #+#    #+#             */
/*   Updated: 2023/07/17 15:01:35 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtrim(char *s1, char *set)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen_s(s1) != 0)
		end = ft_strlen_s(s1) - 1;
	while (ft_isincharset(s1[start], set))
		start++;
	while (end && ft_isincharset(s1[end], set))
		end--;
	if (ft_strlen_s(s1) != 0 && start <= end)
		return (ft_substr(s1, start, end - start + 1));
	return (ft_calloc(1, 1));
}
