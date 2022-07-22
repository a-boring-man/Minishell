/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:30:31 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/09 11:00:51 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_strlen_s(s) + 1, 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}

char	*ft_strndup(char *s, int n)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_min(ft_strlen_s(s), n) + 1, 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i] && i < n)
		dup[i] = s[i];
	return (dup);
}
