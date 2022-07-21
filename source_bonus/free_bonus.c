/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:41:18 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 13:05:55 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_free(void **s)
{
	free(*s);
	*s = 0;
}

char	**ft_free_split(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return (0);
	while (split[++i])
		ft_free((void **)(split + i));
	free(split);
	return (0);
}

t_lt	*ft_free_cmd(t_lt *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while ((cmd + i)->token_type != CMD && (cmd + i)->token_type != PARENTHESE)
	{
		if ((cmd + i)->token_type == HEREDOC)
			close((int) (cmd + i)->token_value - 1);
		else if ((cmd + i)->token_value)
			free((cmd + i)->token_value);
		++i;
	}
	if ((cmd + i)->token_type == CMD)
		ft_free_split((cmd + i)->token_value);
	else if ((cmd + i)->token_value)
		ft_free_big_token((t_bt **)(&((cmd + i)->token_value)), 0, 0);
	free(cmd);
	return (0);
}

t_lt	**ft_free_pipex(t_lt **pipex)
{
	int	i;

	if (pipex)
	{
		i = -1;
		while (pipex[++i])
			pipex[i] = ft_free_cmd(pipex[i]);
		free(pipex);
	}
	return (0);
}
