/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/24 10:54:25 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_gtblock_segmentor(t_minishell *mini, char *c, int *cb,
	t_grostoken *gt, char **block_tmp)
{
	ft_parser_quote_and_or(mini, *c);
	if (mini->et != 2 && mini->ou != 2)
		*block_tmp = ft_strnjoin_f(*block_tmp, c, 1);
	else
	{
		if (ft_strlen_s(*block_tmp) > 1)
		{
			gt[(*cb)].next_operator_type = (*c == '|');
			//gt[*cb++].petit_token = ft_tokenize_pipe(mini, ft_strndup(*block_tmp, ft_strlen_s(*block_tmp) - 1));
			ft_free((void **)(block_tmp)); // normale que ca heap overflow / seg fault car cb ++ dans petit token
			mini->et = 0;
			mini->ou = 0;
		}
		else
		{
			//ft_free((void **)gt);
			return (1);
		}
	}
	return (0);
}

static t_grostoken	*ft_tab_init(t_minishell *mini, char *line, int i, int cb)
{
	char		*block_tmp;
	t_grostoken	*grostoken;

	grostoken = ft_calloc(mini->block, sizeof(t_grostoken));
	ft_parsing_init(mini);
	block_tmp = NULL;
	while (line[++i])
		ft_gtblock_segmentor(mini, &line[i], &cb, grostoken, &block_tmp);
	if (ft_strlen_s(ft_strtrim(block_tmp, "\t\n\v\f\r ")))
	{
		grostoken[cb].next_operator_type = -1;
		//grostoken[cb].petit_token = ft_tokenize_pipe(mini, block_tmp);
	}
	//else
		//ft_free((void **)grostoken);
	return (grostoken);
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
	t_grostoken	*gt;

	if (!ft_good_parenthese_and_quote(mini, line))
		return (0);
	gt = ft_tab_init(mini, line, -1, 0);
	if (!gt)
		printf("parsing error token not recognize\n");
	if (!gt)
		return (0);
	ft_executor(mini, gt);
	return (1);
	/* if (ft_is_a_built_in(line))
		ft_call_built_in(mini, line); */
}
