/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:30:18 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/31 15:32:27 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = ft_calloc(ft_strlen_s(s1) + ft_strlen_s(s2) + 1, 1);
	while (s1 && s1[j])
		new_line[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new_line[i++] = s2[j++];
	if (s1)
		ft_free(&s1);
	return (new_line);
}
