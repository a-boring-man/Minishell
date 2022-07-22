/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/21 20:32:19 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <fcntl.h>

t_lt	**ft_tokenize_pipe(t_minishell *mini, char *line)
{
	int				i;
	int				nb;
	t_lt			**ret;
	char **const	split = ft_super_split(mini, line, '|');
	const int		tmp = mini->cb;

	if (!split)
		return (0);
	i = -1;
	nb = 0;
	while (split[++i])
		++nb;
	ret = ft_calloc(nb + 1, sizeof(void *));
	i = -1;
	while (ret && ++i < nb)
	{
		ret[i] = ft_tokenize_cmd(mini, split[i]);
		mini->cb = tmp;
		if (!ret[i])
			ret = ft_free_pipex(ret);
	}
	ft_free_split(split);
	return (ret);
}
