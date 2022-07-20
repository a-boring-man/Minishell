/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:41:18 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 17:50:55 by jalamell         ###   ########lyon.fr   */
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

t_petit_token	*ft_free_cmd(t_petit_token *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while ((cmd + i)->token_type != CMD && (cmd + i)->token_type != PARENTHESE)
	{
		if ((cmd + i)->token_value)
			free((cmd + i)->token_value);
		++i;
	}
	if ((cmd + i)->token_type == CMD)
		ft_free_split((cmd + i)->token_value);
	else if ((cmd + i)->token_value)
		ft_free_big_token((t_grostoken **)(&((cmd + i)->token_value)), 0, 0);
	free(cmd);
	return (0);
}

t_petit_token	**ft_free_pipex(t_petit_token **pipex)
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
