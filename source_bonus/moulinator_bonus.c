/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 18:31:59 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_free_big_token(t_bt **gt, int cb, int mode)
{
	int	i;

	i = -1;
	if (!gt || !*gt)
		return (1);
	if (mode)
		while (++i < cb)
			ft_free_pipex((*gt)[i].lt);
	else
	{
		while ((*gt)[++i].next_operator_type != -1)
			ft_free_pipex((*gt)[i].lt);
		ft_free_pipex((*gt)[i].lt);
	}
	ft_free((void **)gt);
	return (1);
}

static int	ft_bt_s(t_minishell *mini, char *c, t_bt **gt, char **block_tmp)
{
	ft_parser_quote_and_or(mini, *c);
	if (mini->et != 2 && mini->ou != 2)
		*block_tmp = ft_strnjoin_f(*block_tmp, c, 1);
	else
	{
		if (ft_strlen_s(*block_tmp) > 1)
		{
			ft_bt_ss(mini, *c, *gt, block_tmp);
			if (!(*gt)[mini->cb - 1].lt)
				return (ft_free_big_token(gt, mini->cb - 1, 1));
			ft_mini_et_ou_reset(mini);
		}
		else if (ft_strlen_s(*block_tmp) <= 1)
			return (ft_free_big_token(gt, mini->cb, 1));
		ft_free((void **)(block_tmp));
	}
	return (0);
}

t_bt	*ft_tab_init(t_minishell *mini, char *line, int i)
{
	char	*block_tmp;
	t_bt	*bt;

	mini->cb = 0;
	bt = ft_calloc(mini->block, sizeof(t_bt));
	bt[mini->block - 1].next_operator_type = -1;
	ft_parsing_init(mini);
	block_tmp = ft_calloc(1, 1);
	while (line[++i])
		if (ft_bt_s(mini, &line[i], &bt, &block_tmp))
			return (bt);
	if (ft_strlen_s(block_tmp))
	{
		bt[mini->cb].next_operator_type = -1;
		bt[mini->cb].lt = ft_tokenize_pipe(mini, block_tmp);
		if (!bt[mini->cb].lt)
			ft_free_big_token(&bt, mini->cb, 0);
	}
	else
		ft_free_big_token(&bt, mini->cb, 1);
	ft_free((void **)&block_tmp);
	return (bt);
}

int	ft_good_parenthese_and_quote(t_minishell *mini, char *line)
{
	int	i;

	i = -1;
	ft_parsing_init(mini);
	if (!line)
		return (0);
	while (line[++i])
	{
		if (!mini->block)
			mini->block++;
		ft_parser_quote_and_or(mini, line[i]);
		if (mini->parenthese == -1)
			break ;
		if ((mini->et == 2 || mini->ou == 2) && line[i + 1])
			mini->block++;
		if (mini->et == 2)
			mini->et = 0;
		if (mini->ou == 2)
			mini->ou = 0;
	}
	if (mini->double_quote || mini->parenthese || mini->single_quote)
		printf("parsing error please fix your parenthese/quotes please\n");
	if (mini->double_quote || mini->parenthese || mini->single_quote)
		return (0);
	return (1);
}

int	ft_moulinator(t_minishell *mini, char *line)
{
	t_bt	*gt;

	if (!ft_good_parenthese_and_quote(mini, line))
		return (0);
	if (!line || !line[0])
		return (0);
	gt = ft_tab_init(mini, line, -1);
	if (!gt)
		ft_dprintf(2, "parsing error token not recognize\n");
	if (!gt)
		return (0);
	g_last_error = ft_executor(mini, gt);
	return (ft_free_big_token(&gt, 0, 0));
}
