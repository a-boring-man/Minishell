/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	substr = ft_calloc(ft_min(len, ft_strlen_s(s)) + 1, 1);
	i = -1;
	j = -1;
	if (substr)
		while (s[++i])
			if (i >= start && (i - start) < len)
				substr[++j] = s[i];
	return (substr);
}
