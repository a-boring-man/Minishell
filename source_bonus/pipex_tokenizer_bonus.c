/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tokenizer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/22 11:38:41 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <fcntl.h>

static char	**fast_check(t_minishell *mini, char *line)
{
	int	i;

	i = 0;
	while (line[i])
		++i;
	--i;
	if (i >= 0 && line[i] == '|')
		return (0);
	return (ft_super_split(mini, line, '|'));
}

t_lt	**ft_tokenize_pipe(t_minishell *mini, char *line)
{
	int				i;
	int				nb;
	t_lt			**ret;
	char **const	split = fast_check(mini, line);
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
